#include "ledgerframe/schema.h"

#include <algorithm>
#include <cctype>
#include <cstring>
#include <sstream>

#include "ledgerframe/varint.h"

namespace ledgerframe {

namespace {

std::vector<std::string> split_words(const std::string& line) {
  std::vector<std::string> words;
  std::istringstream input(line);
  std::string word;
  while (input >> word) words.push_back(word);
  return words;
}

uint64_t load_le64(const uint8_t* data) {
  uint64_t value = 0;
  for (int i = 0; i < 8; ++i) value |= static_cast<uint64_t>(data[i]) << (i * 8);
  return value;
}

uint32_t load_le32(const uint8_t* data) {
  uint32_t value = 0;
  for (int i = 0; i < 4; ++i) value |= static_cast<uint32_t>(data[i]) << (i * 8);
  return value;
}

}  // namespace

bool SchemaRegistry::parse_text(const std::string& text, std::string* error) {
  std::istringstream input(text);
  std::string line;
  ChannelSchema current;
  bool have_channel = false;

  while (std::getline(input, line)) {
    line = trim(line);
    if (line.empty() || line[0] == '#') continue;
    const auto words = split_words(line);
    if (words.empty()) continue;

    if (words[0] == "channel") {
      if (have_channel) {
        if (!add_schema(current, error)) return false;
        current = ChannelSchema{};
      }
      if (words.size() < 2) {
        if (error) *error = "channel name missing";
        return false;
      }
      current.channel = words[1];
      current.version = 1;
      have_channel = true;
      for (size_t i = 2; i < words.size(); ++i) {
        if (words[i].find("version=") == 0) {
          current.version = static_cast<uint32_t>(std::stoul(words[i].substr(8)));
        }
      }
      continue;
    }

    if (words[0] == "field") {
      if (!have_channel) {
        if (error) *error = "field without channel";
        return false;
      }
      FieldDefinition field;
      if (!parse_field(line, &field, error)) return false;
      current.fields.push_back(field);
      continue;
    }

    if (error) *error = "unknown schema directive";
    return false;
  }

  if (have_channel && !add_schema(current, error)) return false;
  return true;
}

bool SchemaRegistry::add_schema(const ChannelSchema& schema, std::string* error) {
  if (schema.channel.empty()) {
    if (error) *error = "empty channel";
    return false;
  }
  if (schema.fields.empty()) {
    if (error) *error = "schema has no fields";
    return false;
  }

  std::map<uint32_t, bool> tags;
  std::map<std::string, bool> names;
  for (const auto& field : schema.fields) {
    if (field.name.empty()) {
      if (error) *error = "empty field name";
      return false;
    }
    if (tags[field.tag]) {
      if (error) *error = "duplicate field tag";
      return false;
    }
    if (names[field.name]) {
      if (error) *error = "duplicate field name";
      return false;
    }
    tags[field.tag] = true;
    names[field.name] = true;
  }

  schemas_[schema.channel] = schema;
  return true;
}

const ChannelSchema* SchemaRegistry::find(const std::string& channel) const {
  auto it = schemas_.find(channel);
  if (it == schemas_.end()) return nullptr;
  return &it->second;
}

std::vector<std::string> SchemaRegistry::channels() const {
  std::vector<std::string> out;
  for (const auto& item : schemas_) out.push_back(item.first);
  return out;
}

bool SchemaRegistry::parse_field(const std::string& line, FieldDefinition* out, std::string* error) {
  const auto words = split_words(line);
  if (words.size() < 4) {
    if (error) *error = "field directive too short";
    return false;
  }
  out->name = words[1];
  if (!parse_type(words[2], &out->type)) {
    if (error) *error = "unknown field type";
    return false;
  }
  out->tag = static_cast<uint32_t>(std::stoul(words[3]));
  out->required = false;
  out->max_length = 0;
  for (size_t i = 4; i < words.size(); ++i) {
    if (words[i] == "required") out->required = true;
    else if (words[i].find("max=") == 0) out->max_length = static_cast<uint32_t>(std::stoul(words[i].substr(4)));
  }
  return true;
}

bool SchemaRegistry::parse_type(const std::string& text, FieldType* out) {
  if (text == "i64") *out = FieldType::kInt64;
  else if (text == "u64") *out = FieldType::kUInt64;
  else if (text == "f64") *out = FieldType::kDouble;
  else if (text == "bool") *out = FieldType::kBool;
  else if (text == "string") *out = FieldType::kString;
  else if (text == "bytes") *out = FieldType::kBytes;
  else return false;
  return true;
}

std::string SchemaRegistry::trim(const std::string& text) {
  size_t begin = 0;
  while (begin < text.size() && std::isspace(static_cast<unsigned char>(text[begin]))) ++begin;
  size_t end = text.size();
  while (end > begin && std::isspace(static_cast<unsigned char>(text[end - 1]))) --end;
  return text.substr(begin, end - begin);
}

bool PayloadDecoder::decode(const ChannelSchema& schema, const Frame& frame,
                            std::vector<DecodedField>* fields, std::string* error) const {
  fields->clear();
  VarintReader reader(frame.payload.data(), frame.payload.size());
  std::map<uint32_t, DecodedField> seen;

  while (reader.remaining() > 0) {
    uint64_t tag = 0;
    uint64_t length = 0;
    if (!reader.read_u64(&tag) || !reader.read_u64(&length)) {
      if (error) *error = "truncated field header";
      return false;
    }
    const uint8_t* bytes = nullptr;
    if (!reader.read_bytes(&bytes, static_cast<size_t>(length))) {
      if (error) *error = "truncated field value";
      return false;
    }
    auto found = std::find_if(schema.fields.begin(), schema.fields.end(),
                              [tag](const FieldDefinition& field) { return field.tag == tag; });
    if (found == schema.fields.end()) continue;

    DecodedField decoded;
    if (!decode_one(*found, bytes, static_cast<size_t>(length), &decoded, error)) return false;
    seen[found->tag] = decoded;
  }

  for (const auto& definition : schema.fields) {
    auto found = seen.find(definition.tag);
    if (found == seen.end()) {
      if (definition.required) {
        if (error) *error = "required field missing";
        return false;
      }
      continue;
    }
    fields->push_back(found->second);
  }
  return true;
}

bool PayloadDecoder::decode_one(const FieldDefinition& definition, const uint8_t* data, size_t size,
                                DecodedField* out, std::string* error) const {
  out->name = definition.name;
  out->type = definition.type;
  out->bytes_value.assign(data, data + size);

  if (definition.max_length != 0 && size > definition.max_length) {
    if (error) *error = "field exceeds max length";
    return false;
  }

  switch (definition.type) {
    case FieldType::kInt64: {
      VarintReader reader(data, size);
      if (!reader.read_i64(&out->signed_value) || reader.remaining() != 0) {
        if (error) *error = "invalid i64";
        return false;
      }
      out->text_value = std::to_string(out->signed_value);
      return true;
    }
    case FieldType::kUInt64: {
      VarintReader reader(data, size);
      if (!reader.read_u64(&out->unsigned_value) || reader.remaining() != 0) {
        if (error) *error = "invalid u64";
        return false;
      }
      out->text_value = std::to_string(out->unsigned_value);
      return true;
    }
    case FieldType::kDouble: {
      if (size != 8) {
        if (error) *error = "invalid f64";
        return false;
      }
      const uint64_t bits = load_le64(data);
      std::memcpy(&out->double_value, &bits, sizeof(out->double_value));
      out->text_value = std::to_string(out->double_value);
      return true;
    }
    case FieldType::kBool:
      if (size != 1) {
        if (error) *error = "invalid bool";
        return false;
      }
      out->bool_value = data[0] != 0;
      out->text_value = out->bool_value ? "true" : "false";
      return true;
    case FieldType::kString:
      out->text_value.assign(reinterpret_cast<const char*>(data), size);
      return true;
    case FieldType::kBytes:
      out->unsigned_value = size >= 4 ? load_le32(data) : 0;
      return true;
  }
  return false;
}

}  // namespace ledgerframe
