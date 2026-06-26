#pragma once

#include <cstddef>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "ledgerframe/frame_reader.h"

namespace ledgerframe {

struct TimelinePoint {
  uint64_t timestamp_ms = 0;
  std::string channel;
  uint64_t ordinal = 0;
  uint64_t payload_size = 0;
};

struct TimelineGap {
  std::string channel;
  uint64_t previous_ms = 0;
  uint64_t next_ms = 0;
  uint64_t gap_ms = 0;
};

class Timeline {
 public:
  void clear();
  void add(const Frame& frame, uint64_t ordinal);
  void add_many(const std::vector<Frame>& frames);
  std::vector<TimelinePoint> points() const;
  std::vector<TimelinePoint> range(uint64_t start_ms, uint64_t end_ms) const;
  std::vector<TimelineGap> gaps(uint64_t minimum_gap_ms) const;
  std::string render() const;

 private:
  std::vector<TimelinePoint> points_;
};

class ClockSkewDetector {
 public:
  explicit ClockSkewDetector(uint64_t tolerance_ms);
  std::vector<TimelineGap> detect_backward_jumps(const Timeline& timeline) const;

 private:
  uint64_t tolerance_ms_;
};

class TimelineCursor {
 public:
  explicit TimelineCursor(std::vector<TimelinePoint> points);
  bool seek(uint64_t timestamp_ms);
  bool next(TimelinePoint* point);
  bool previous(TimelinePoint* point);
  size_t position() const;

 private:
  std::vector<TimelinePoint> points_;
  size_t position_ = 0;
};

struct RateSample {
  std::string channel;
  uint64_t start_ms = 0;
  uint64_t end_ms = 0;
  double frames_per_second = 0.0;
  double bytes_per_second = 0.0;
};

class RateEstimator {
 public:
  explicit RateEstimator(uint64_t window_ms);
  std::vector<RateSample> estimate(const Timeline& timeline) const;

 private:
  uint64_t window_ms_;
};

}  // namespace ledgerframe
