#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "ledgerframe/frame_reader.h"
#include "ledgerframe/query.h"

namespace ledgerframe {

struct AggregateBucket {
  std::string channel;
  uint64_t start_ms = 0;
  uint64_t end_ms = 0;
  uint64_t count = 0;
  double min_value = 0.0;
  double max_value = 0.0;
  double sum_value = 0.0;
};

class Aggregator {
 public:
  explicit Aggregator(uint64_t bucket_width_ms);

  void clear();
  bool observe(const Frame& frame, const QueryProgram* filter);
  std::vector<AggregateBucket> buckets() const;
  std::string render_table() const;

 private:
  struct Key {
    std::string channel;
    uint64_t start_ms = 0;
    bool operator<(const Key& other) const;
  };

  static bool parse_payload_number(const std::vector<uint8_t>& payload, double* value);

  uint64_t bucket_width_ms_;
  std::map<Key, AggregateBucket> buckets_;
};

}  // namespace ledgerframe
