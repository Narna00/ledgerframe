#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "ledgerframe/frame_reader.h"
#include "ledgerframe/manifest.h"

namespace ledgerframe {

struct RetentionRule {
  std::string channel_prefix;
  uint64_t keep_for_ms = 0;
  uint64_t sample_every = 1;
};

class RetentionPolicy {
 public:
  bool parse_text(const std::string& text);
  bool keep_frame(const Frame& frame, uint64_t now_ms, uint64_t ordinal) const;
  std::vector<SegmentDescriptor> expired_segments(const Manifest& manifest, uint64_t now_ms) const;
  const std::vector<RetentionRule>& rules() const;

 private:
  static bool parse_rule(const std::string& line, RetentionRule* rule);
  static bool has_prefix(const std::string& value, const std::string& prefix);

  std::vector<RetentionRule> rules_;
};

class Downsampler {
 public:
  explicit Downsampler(RetentionPolicy policy);
  std::vector<Frame> apply(const std::vector<Frame>& frames, uint64_t now_ms) const;

 private:
  RetentionPolicy policy_;
};

}  // namespace ledgerframe
