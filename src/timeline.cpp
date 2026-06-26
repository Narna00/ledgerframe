#include "ledgerframe/timeline.h"

#include <algorithm>
#include <sstream>
#include <utility>

namespace ledgerframe {

void Timeline::clear() {
  points_.clear();
}

void Timeline::add(const Frame& frame, uint64_t ordinal) {
  TimelinePoint point;
  point.timestamp_ms = frame.timestamp_ms;
  point.channel = frame.channel;
  point.ordinal = ordinal;
  point.payload_size = frame.payload.size();
  points_.push_back(std::move(point));
}

void Timeline::add_many(const std::vector<Frame>& frames) {
  for (uint64_t i = 0; i < frames.size(); ++i) add(frames[static_cast<size_t>(i)], i);
}

std::vector<TimelinePoint> Timeline::points() const {
  std::vector<TimelinePoint> out = points_;
  std::sort(out.begin(), out.end(), [](const TimelinePoint& a, const TimelinePoint& b) {
    if (a.timestamp_ms != b.timestamp_ms) return a.timestamp_ms < b.timestamp_ms;
    if (a.channel != b.channel) return a.channel < b.channel;
    return a.ordinal < b.ordinal;
  });
  return out;
}

std::vector<TimelinePoint> Timeline::range(uint64_t start_ms, uint64_t end_ms) const {
  std::vector<TimelinePoint> out;
  for (const auto& point : points_) {
    if (point.timestamp_ms >= start_ms && point.timestamp_ms <= end_ms) out.push_back(point);
  }
  std::sort(out.begin(), out.end(), [](const TimelinePoint& a, const TimelinePoint& b) {
    return a.timestamp_ms < b.timestamp_ms;
  });
  return out;
}

std::vector<TimelineGap> Timeline::gaps(uint64_t minimum_gap_ms) const {
  std::map<std::string, std::vector<TimelinePoint>> by_channel;
  for (const auto& point : points_) by_channel[point.channel].push_back(point);

  std::vector<TimelineGap> out;
  for (auto& item : by_channel) {
    auto& points = item.second;
    std::sort(points.begin(), points.end(), [](const TimelinePoint& a, const TimelinePoint& b) {
      return a.timestamp_ms < b.timestamp_ms;
    });
    for (size_t i = 1; i < points.size(); ++i) {
      const uint64_t previous = points[i - 1].timestamp_ms;
      const uint64_t current = points[i].timestamp_ms;
      if (current >= previous && current - previous >= minimum_gap_ms) {
        TimelineGap gap;
        gap.channel = item.first;
        gap.previous_ms = previous;
        gap.next_ms = current;
        gap.gap_ms = current - previous;
        out.push_back(gap);
      }
    }
  }
  return out;
}

std::string Timeline::render() const {
  std::ostringstream out;
  for (const auto& point : points()) {
    out << point.timestamp_ms << ' ' << point.channel << ' '
        << point.ordinal << ' ' << point.payload_size << '\n';
  }
  return out.str();
}

ClockSkewDetector::ClockSkewDetector(uint64_t tolerance_ms) : tolerance_ms_(tolerance_ms) {}

std::vector<TimelineGap> ClockSkewDetector::detect_backward_jumps(const Timeline& timeline) const {
  std::map<std::string, TimelinePoint> last;
  std::vector<TimelineGap> out;
  for (const auto& point : timeline.points()) {
    auto found = last.find(point.channel);
    if (found != last.end() && found->second.timestamp_ms > point.timestamp_ms + tolerance_ms_) {
      TimelineGap gap;
      gap.channel = point.channel;
      gap.previous_ms = found->second.timestamp_ms;
      gap.next_ms = point.timestamp_ms;
      gap.gap_ms = found->second.timestamp_ms - point.timestamp_ms;
      out.push_back(gap);
    }
    last[point.channel] = point;
  }
  return out;
}

TimelineCursor::TimelineCursor(std::vector<TimelinePoint> points) : points_(std::move(points)) {
  std::sort(points_.begin(), points_.end(), [](const TimelinePoint& a, const TimelinePoint& b) {
    if (a.timestamp_ms != b.timestamp_ms) return a.timestamp_ms < b.timestamp_ms;
    return a.ordinal < b.ordinal;
  });
}

bool TimelineCursor::seek(uint64_t timestamp_ms) {
  auto it = std::lower_bound(points_.begin(), points_.end(), timestamp_ms,
                             [](const TimelinePoint& point, uint64_t value) {
                               return point.timestamp_ms < value;
                             });
  position_ = static_cast<size_t>(it - points_.begin());
  return position_ < points_.size();
}

bool TimelineCursor::next(TimelinePoint* point) {
  if (position_ >= points_.size()) return false;
  *point = points_[position_++];
  return true;
}

bool TimelineCursor::previous(TimelinePoint* point) {
  if (position_ == 0 || points_.empty()) return false;
  --position_;
  *point = points_[position_];
  return true;
}

size_t TimelineCursor::position() const {
  return position_;
}

RateEstimator::RateEstimator(uint64_t window_ms) : window_ms_(window_ms == 0 ? 60000 : window_ms) {}

std::vector<RateSample> RateEstimator::estimate(const Timeline& timeline) const {
  std::map<std::string, std::vector<TimelinePoint>> by_channel;
  for (const auto& point : timeline.points()) by_channel[point.channel].push_back(point);

  std::vector<RateSample> out;
  for (auto& item : by_channel) {
    auto& points = item.second;
    if (points.empty()) continue;
    uint64_t window_start = (points.front().timestamp_ms / window_ms_) * window_ms_;
    uint64_t window_end = window_start + window_ms_;
    uint64_t frames = 0;
    uint64_t bytes = 0;

    for (const auto& point : points) {
      while (point.timestamp_ms >= window_end) {
        RateSample sample;
        sample.channel = item.first;
        sample.start_ms = window_start;
        sample.end_ms = window_end;
        const double seconds = static_cast<double>(window_ms_) / 1000.0;
        sample.frames_per_second = seconds == 0.0 ? 0.0 : static_cast<double>(frames) / seconds;
        sample.bytes_per_second = seconds == 0.0 ? 0.0 : static_cast<double>(bytes) / seconds;
        out.push_back(sample);
        window_start = window_end;
        window_end += window_ms_;
        frames = 0;
        bytes = 0;
      }
      frames += 1;
      bytes += point.payload_size;
    }

    RateSample sample;
    sample.channel = item.first;
    sample.start_ms = window_start;
    sample.end_ms = window_end;
    const double seconds = static_cast<double>(window_ms_) / 1000.0;
    sample.frames_per_second = seconds == 0.0 ? 0.0 : static_cast<double>(frames) / seconds;
    sample.bytes_per_second = seconds == 0.0 ? 0.0 : static_cast<double>(bytes) / seconds;
    out.push_back(sample);
  }
  return out;
}

}  // namespace ledgerframe
