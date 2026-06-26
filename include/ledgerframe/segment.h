#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "ledgerframe/batch_reader.h"
#include "ledgerframe/manifest.h"
#include "ledgerframe/query.h"

namespace ledgerframe {

struct SegmentStats {
  uint64_t frames = 0;
  uint64_t bytes = 0;
  uint64_t first_timestamp_ms = 0;
  uint64_t last_timestamp_ms = 0;
  std::vector<std::string> channels;
};

class SegmentReader {
 public:
  bool parse_segment(const uint8_t* data, size_t size, Batch* batch, SegmentStats* stats);
  std::vector<Frame> filter(const Batch& batch, const QueryProgram& query) const;

 private:
  void update_stats(const Batch& batch, size_t byte_size, SegmentStats* stats) const;
};

class SegmentPlanner {
 public:
  explicit SegmentPlanner(Manifest manifest);
  std::vector<SegmentDescriptor> plan(uint64_t start_ms, uint64_t end_ms,
                                      const std::string& channel) const;
  uint64_t estimate_records(const std::vector<SegmentDescriptor>& segments) const;

 private:
  Manifest manifest_;
};

}  // namespace ledgerframe
