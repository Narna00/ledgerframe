#include "ledgerframe/segment.h"

#include <algorithm>
#include <set>
#include <utility>

namespace ledgerframe {

bool SegmentReader::parse_segment(const uint8_t* data, size_t size, Batch* batch, SegmentStats* stats) {
  BatchReader reader;
  if (!reader.parse(data, size, batch)) return false;
  update_stats(*batch, size, stats);
  return true;
}

std::vector<Frame> SegmentReader::filter(const Batch& batch, const QueryProgram& query) const {
  std::vector<Frame> out;
  for (const auto& frame : batch.frames) {
    if (query.evaluate(frame)) out.push_back(frame);
  }
  return out;
}

void SegmentReader::update_stats(const Batch& batch, size_t byte_size, SegmentStats* stats) const {
  stats->frames = batch.frames.size();
  stats->bytes = byte_size;
  stats->first_timestamp_ms = 0;
  stats->last_timestamp_ms = 0;
  stats->channels.clear();

  std::set<std::string> channels;
  for (const auto& frame : batch.frames) {
    if (stats->first_timestamp_ms == 0 || frame.timestamp_ms < stats->first_timestamp_ms) {
      stats->first_timestamp_ms = frame.timestamp_ms;
    }
    if (frame.timestamp_ms > stats->last_timestamp_ms) stats->last_timestamp_ms = frame.timestamp_ms;
    channels.insert(frame.channel);
  }
  stats->channels.assign(channels.begin(), channels.end());
}

SegmentPlanner::SegmentPlanner(Manifest manifest) : manifest_(std::move(manifest)) {}

std::vector<SegmentDescriptor> SegmentPlanner::plan(uint64_t start_ms, uint64_t end_ms,
                                                    const std::string& channel) const {
  auto segments = manifest_.select(start_ms, end_ms, channel);
  std::sort(segments.begin(), segments.end(),
            [](const SegmentDescriptor& a, const SegmentDescriptor& b) {
              if (a.start_ms != b.start_ms) return a.start_ms < b.start_ms;
              return a.path < b.path;
            });
  return segments;
}

uint64_t SegmentPlanner::estimate_records(const std::vector<SegmentDescriptor>& segments) const {
  uint64_t total = 0;
  for (const auto& segment : segments) total += segment.records;
  return total;
}

}  // namespace ledgerframe
