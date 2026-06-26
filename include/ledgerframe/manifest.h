#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace ledgerframe {

struct SegmentDescriptor {
  std::string path;
  uint64_t start_ms = 0;
  uint64_t end_ms = 0;
  uint64_t records = 0;
  std::string primary_channel;
};

class Manifest {
 public:
  bool parse_text(const std::string& text);
  std::string serialize_text() const;
  std::vector<SegmentDescriptor> select(uint64_t start_ms, uint64_t end_ms,
                                        const std::string& channel) const;
  const std::vector<SegmentDescriptor>& segments() const;

 private:
  static bool parse_line(const std::string& line, SegmentDescriptor* out);
  static std::vector<std::string> split_fields(const std::string& line);

  std::vector<SegmentDescriptor> segments_;
};

}  // namespace ledgerframe
