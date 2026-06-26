#include "ledgerframe/catalog.h"

#include <sstream>
#include <utility>

namespace ledgerframe {

void ChannelCatalog::clear() {
  channels_.clear();
}

void ChannelCatalog::observe(const Frame& frame) {
  auto& info = channels_[frame.channel];
  if (info.name.empty()) info.name = frame.channel;
  info.frames += 1;
  info.payload_bytes += frame.payload.size();
  info.observed_flags |= frame.flags;
  if (info.first_timestamp_ms == 0 || frame.timestamp_ms < info.first_timestamp_ms) {
    info.first_timestamp_ms = frame.timestamp_ms;
  }
  if (frame.timestamp_ms > info.last_timestamp_ms) info.last_timestamp_ms = frame.timestamp_ms;
}

void ChannelCatalog::merge(const ChannelCatalog& other) {
  for (const auto& item : other.channels_) {
    const ChannelInfo& rhs = item.second;
    auto& lhs = channels_[rhs.name];
    if (lhs.name.empty()) lhs.name = rhs.name;
    lhs.frames += rhs.frames;
    lhs.payload_bytes += rhs.payload_bytes;
    lhs.observed_flags |= rhs.observed_flags;
    if (lhs.first_timestamp_ms == 0 ||
        (rhs.first_timestamp_ms != 0 && rhs.first_timestamp_ms < lhs.first_timestamp_ms)) {
      lhs.first_timestamp_ms = rhs.first_timestamp_ms;
    }
    if (rhs.last_timestamp_ms > lhs.last_timestamp_ms) lhs.last_timestamp_ms = rhs.last_timestamp_ms;
  }
}

const ChannelInfo* ChannelCatalog::find(const std::string& channel) const {
  auto found = channels_.find(channel);
  if (found == channels_.end()) return nullptr;
  return &found->second;
}

std::vector<ChannelInfo> ChannelCatalog::list() const {
  std::vector<ChannelInfo> out;
  for (const auto& item : channels_) out.push_back(item.second);
  return out;
}

std::vector<std::string> ChannelCatalog::names_with_prefix(const std::string& prefix) const {
  std::vector<std::string> out;
  for (const auto& item : channels_) {
    if (prefix.empty() || item.first.compare(0, prefix.size(), prefix) == 0) {
      out.push_back(item.first);
    }
  }
  return out;
}

std::string ChannelCatalog::render_text() const {
  std::ostringstream out;
  for (const auto& item : channels_) {
    const ChannelInfo& info = item.second;
    out << info.name << ' ' << info.frames << ' ' << info.payload_bytes << ' '
        << info.first_timestamp_ms << ' ' << info.last_timestamp_ms << ' '
        << info.observed_flags << '\n';
  }
  return out.str();
}

ChannelPattern::ChannelPattern(std::string pattern) : pattern_(std::move(pattern)) {}

bool ChannelPattern::matches(const std::string& channel) const {
  return matches_here(0, 0, channel);
}

bool ChannelPattern::matches_here(size_t pattern_pos, size_t channel_pos, const std::string& channel) const {
  while (pattern_pos < pattern_.size()) {
    const char p = pattern_[pattern_pos];
    if (p == '*') {
      while (pattern_pos + 1 < pattern_.size() && pattern_[pattern_pos + 1] == '*') ++pattern_pos;
      if (pattern_pos + 1 == pattern_.size()) return true;
      for (size_t i = channel_pos; i <= channel.size(); ++i) {
        if (matches_here(pattern_pos + 1, i, channel)) return true;
      }
      return false;
    }
    if (channel_pos >= channel.size()) return false;
    if (p != '?' && p != channel[channel_pos]) return false;
    ++pattern_pos;
    ++channel_pos;
  }
  return channel_pos == channel.size();
}

}  // namespace ledgerframe
