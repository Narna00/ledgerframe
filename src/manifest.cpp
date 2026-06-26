#include "ledgerframe/manifest.h"

#include <sstream>

namespace ledgerframe {

bool Manifest::parse_text(const std::string& text) {
  segments_.clear();
  std::istringstream input(text);
  std::string line;
  while (std::getline(input, line)) {
    if (line.empty() || line[0] == '#') continue;
    SegmentDescriptor descriptor;
    if (!parse_line(line, &descriptor)) return false;
    segments_.push_back(descriptor);
  }
  return true;
}

std::string Manifest::serialize_text() const {
  std::ostringstream out;
  for (const auto& segment : segments_) {
    out << segment.path << '\t' << segment.start_ms << '\t' << segment.end_ms
        << '\t' << segment.records << '\t' << segment.primary_channel << '\n';
  }
  return out.str();
}

std::vector<SegmentDescriptor> Manifest::select(uint64_t start_ms, uint64_t end_ms,
                                                const std::string& channel) const {
  std::vector<SegmentDescriptor> out;
  for (const auto& segment : segments_) {
    if (segment.end_ms < start_ms || segment.start_ms > end_ms) continue;
    if (!channel.empty() && !segment.primary_channel.empty() && segment.primary_channel != channel) continue;
    out.push_back(segment);
  }
  return out;
}

const std::vector<SegmentDescriptor>& Manifest::segments() const {
  return segments_;
}

bool Manifest::parse_line(const std::string& line, SegmentDescriptor* out) {
  const auto fields = split_fields(line);
  if (fields.size() < 5) return false;
  out->path = fields[0];
  out->start_ms = std::stoull(fields[1]);
  out->end_ms = std::stoull(fields[2]);
  out->records = std::stoull(fields[3]);
  out->primary_channel = fields[4];
  return out->start_ms <= out->end_ms;
}

std::vector<std::string> Manifest::split_fields(const std::string& line) {
  std::vector<std::string> fields;
  std::string current;
  for (char c : line) {
    if (c == '\t' || c == ',') {
      fields.push_back(current);
      current.clear();
    } else {
      current.push_back(c);
    }
  }
  fields.push_back(current);
  return fields;
}

}  // namespace ledgerframe
