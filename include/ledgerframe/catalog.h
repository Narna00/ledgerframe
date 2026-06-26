#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "ledgerframe/frame_reader.h"

namespace ledgerframe {

struct ChannelInfo {
  std::string name;
  uint64_t frames = 0;
  uint64_t payload_bytes = 0;
  uint64_t first_timestamp_ms = 0;
  uint64_t last_timestamp_ms = 0;
  uint16_t observed_flags = 0;
};

class ChannelCatalog {
 public:
  void clear();
  void observe(const Frame& frame);
  void merge(const ChannelCatalog& other);
  const ChannelInfo* find(const std::string& channel) const;
  std::vector<ChannelInfo> list() const;
  std::vector<std::string> names_with_prefix(const std::string& prefix) const;
  std::string render_text() const;

 private:
  std::map<std::string, ChannelInfo> channels_;
};

class ChannelPattern {
 public:
  explicit ChannelPattern(std::string pattern);
  bool matches(const std::string& channel) const;

 private:
  bool matches_here(size_t pattern_pos, size_t channel_pos, const std::string& channel) const;

  std::string pattern_;
};

}  // namespace ledgerframe
