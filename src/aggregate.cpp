#include "ledgerframe/aggregate.h"

#include <cstdlib>
#include <iomanip>
#include <sstream>

namespace ledgerframe {

Aggregator::Aggregator(uint64_t bucket_width_ms)
    : bucket_width_ms_(bucket_width_ms == 0 ? 60000 : bucket_width_ms) {}

void Aggregator::clear() {
  buckets_.clear();
}

bool Aggregator::observe(const Frame& frame, const QueryProgram* filter) {
  if (filter && !filter->evaluate(frame)) return false;
  double value = 0.0;
  if (!parse_payload_number(frame.payload, &value)) return false;
  const uint64_t start = (frame.timestamp_ms / bucket_width_ms_) * bucket_width_ms_;
  Key key{frame.channel, start};
  auto& bucket = buckets_[key];
  if (bucket.count == 0) {
    bucket.channel = frame.channel;
    bucket.start_ms = start;
    bucket.end_ms = start + bucket_width_ms_;
    bucket.min_value = value;
    bucket.max_value = value;
  } else {
    if (value < bucket.min_value) bucket.min_value = value;
    if (value > bucket.max_value) bucket.max_value = value;
  }
  bucket.sum_value += value;
  bucket.count += 1;
  return true;
}

std::vector<AggregateBucket> Aggregator::buckets() const {
  std::vector<AggregateBucket> out;
  for (const auto& item : buckets_) out.push_back(item.second);
  return out;
}

std::string Aggregator::render_table() const {
  std::ostringstream out;
  out << "channel,start_ms,end_ms,count,min,max,avg\n";
  for (const auto& item : buckets_) {
    const auto& bucket = item.second;
    const double avg = bucket.count == 0 ? 0.0 : bucket.sum_value / static_cast<double>(bucket.count);
    out << bucket.channel << ',' << bucket.start_ms << ',' << bucket.end_ms << ','
        << bucket.count << ',' << std::setprecision(12) << bucket.min_value << ','
        << bucket.max_value << ',' << avg << '\n';
  }
  return out.str();
}

bool Aggregator::Key::operator<(const Key& other) const {
  if (channel != other.channel) return channel < other.channel;
  return start_ms < other.start_ms;
}

bool Aggregator::parse_payload_number(const std::vector<uint8_t>& payload, double* value) {
  if (payload.empty()) return false;
  std::string text;
  text.reserve(payload.size());
  for (uint8_t b : payload) {
    if (b == 0) break;
    text.push_back(static_cast<char>(b));
  }
  char* end = nullptr;
  const double parsed = std::strtod(text.c_str(), &end);
  if (end == text.c_str()) return false;
  *value = parsed;
  return true;
}

}  // namespace ledgerframe
