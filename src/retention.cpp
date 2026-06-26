#include "ledgerframe/retention.h"

#include <sstream>
#include <utility>

namespace ledgerframe {

bool RetentionPolicy::parse_text(const std::string& text) {
  rules_.clear();
  std::istringstream input(text);
  std::string line;
  while (std::getline(input, line)) {
    if (line.empty() || line[0] == '#') continue;
    RetentionRule rule;
    if (!parse_rule(line, &rule)) return false;
    rules_.push_back(rule);
  }
  return true;
}

bool RetentionPolicy::keep_frame(const Frame& frame, uint64_t now_ms, uint64_t ordinal) const {
  for (const auto& rule : rules_) {
    if (!has_prefix(frame.channel, rule.channel_prefix)) continue;
    if (rule.keep_for_ms != 0 && frame.timestamp_ms + rule.keep_for_ms < now_ms) return false;
    if (rule.sample_every > 1 && ordinal % rule.sample_every != 0) return false;
    return true;
  }
  return true;
}

std::vector<SegmentDescriptor> RetentionPolicy::expired_segments(const Manifest& manifest, uint64_t now_ms) const {
  std::vector<SegmentDescriptor> expired;
  for (const auto& segment : manifest.segments()) {
    for (const auto& rule : rules_) {
      if (!has_prefix(segment.primary_channel, rule.channel_prefix)) continue;
      if (rule.keep_for_ms != 0 && segment.end_ms + rule.keep_for_ms < now_ms) {
        expired.push_back(segment);
      }
      break;
    }
  }
  return expired;
}

const std::vector<RetentionRule>& RetentionPolicy::rules() const {
  return rules_;
}

bool RetentionPolicy::parse_rule(const std::string& line, RetentionRule* rule) {
  std::istringstream input(line);
  if (!(input >> rule->channel_prefix >> rule->keep_for_ms)) return false;
  rule->sample_every = 1;
  input >> rule->sample_every;
  if (rule->sample_every == 0) rule->sample_every = 1;
  return true;
}

bool RetentionPolicy::has_prefix(const std::string& value, const std::string& prefix) {
  if (prefix == "*" || prefix.empty()) return true;
  if (value.size() < prefix.size()) return false;
  return value.compare(0, prefix.size(), prefix) == 0;
}

Downsampler::Downsampler(RetentionPolicy policy) : policy_(std::move(policy)) {}

std::vector<Frame> Downsampler::apply(const std::vector<Frame>& frames, uint64_t now_ms) const {
  std::vector<Frame> out;
  out.reserve(frames.size());
  uint64_t ordinal = 0;
  for (const auto& frame : frames) {
    if (policy_.keep_frame(frame, now_ms, ordinal)) out.push_back(frame);
    ++ordinal;
  }
  return out;
}

}  // namespace ledgerframe
