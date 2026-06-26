#include "ledgerframe/normalize.h"

#include <iomanip>
#include <set>
#include <sstream>
#include <utility>

namespace ledgerframe {

Normalizer::Normalizer(SchemaRegistry registry) : registry_(std::move(registry)) {}

bool Normalizer::normalize(const Frame& frame, NormalizedRecord* record, std::string* error) const {
  record->channel = frame.channel;
  record->timestamp_ms = frame.timestamp_ms;
  record->fields.clear();

  const ChannelSchema* schema = registry_.find(frame.channel);
  if (!schema) {
    record->fields["payload_hex"] = bytes_to_hex(frame.payload);
    record->fields["payload_size"] = std::to_string(frame.payload.size());
    return true;
  }

  PayloadDecoder decoder;
  std::vector<DecodedField> decoded;
  if (!decoder.decode(*schema, frame, &decoded, error)) return false;
  for (const auto& field : decoded) {
    if (field.type == FieldType::kBytes) record->fields[field.name] = bytes_to_hex(field.bytes_value);
    else record->fields[field.name] = field.text_value;
  }
  return true;
}

std::vector<NormalizedRecord> Normalizer::normalize_many(const std::vector<Frame>& frames) const {
  std::vector<NormalizedRecord> out;
  out.reserve(frames.size());
  for (const auto& frame : frames) {
    NormalizedRecord record;
    std::string error;
    if (normalize(frame, &record, &error)) out.push_back(std::move(record));
  }
  return out;
}

std::string Normalizer::render_csv(const std::vector<NormalizedRecord>& records) const {
  std::set<std::string> columns;
  for (const auto& record : records) {
    for (const auto& item : record.fields) columns.insert(item.first);
  }

  std::ostringstream out;
  out << "channel,timestamp_ms";
  for (const auto& column : columns) out << ',' << escape_csv(column);
  out << '\n';

  for (const auto& record : records) {
    out << escape_csv(record.channel) << ',' << record.timestamp_ms;
    for (const auto& column : columns) {
      out << ',';
      auto found = record.fields.find(column);
      if (found != record.fields.end()) out << escape_csv(found->second);
    }
    out << '\n';
  }
  return out.str();
}

std::string Normalizer::escape_csv(const std::string& value) {
  bool needs_quote = false;
  for (char c : value) {
    if (c == ',' || c == '"' || c == '\n' || c == '\r') {
      needs_quote = true;
      break;
    }
  }
  if (!needs_quote) return value;
  std::string out = "\"";
  for (char c : value) {
    if (c == '"') out.push_back('"');
    out.push_back(c);
  }
  out.push_back('"');
  return out;
}

std::string Normalizer::bytes_to_hex(const std::vector<uint8_t>& bytes) {
  std::ostringstream out;
  out << std::hex << std::setfill('0');
  for (uint8_t b : bytes) out << std::setw(2) << static_cast<unsigned>(b);
  return out.str();
}

RecordProjector::RecordProjector(std::vector<std::string> columns) : columns_(std::move(columns)) {}

std::vector<std::string> RecordProjector::project(const NormalizedRecord& record) const {
  std::vector<std::string> out;
  out.reserve(columns_.size());
  for (const auto& column : columns_) {
    if (column == "channel") out.push_back(record.channel);
    else if (column == "timestamp_ms") out.push_back(std::to_string(record.timestamp_ms));
    else {
      auto found = record.fields.find(column);
      out.push_back(found == record.fields.end() ? std::string() : found->second);
    }
  }
  return out;
}

const std::vector<std::string>& RecordProjector::columns() const {
  return columns_;
}

}  // namespace ledgerframe
