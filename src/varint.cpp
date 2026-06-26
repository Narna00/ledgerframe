#include "ledgerframe/varint.h"

namespace ledgerframe {

VarintReader::VarintReader(const uint8_t* data, size_t size)
    : data_(data), size_(size), pos_(0) {}

bool VarintReader::read_u64(uint64_t* value) {
  uint64_t result = 0;
  uint32_t shift = 0;
  while (shift <= 63 && pos_ < size_) {
    const uint8_t byte = data_[pos_++];
    if (shift == 63 && (byte & 0xfeu) != 0) return false;
    result |= static_cast<uint64_t>(byte & 0x7fu) << shift;
    if ((byte & 0x80u) == 0) {
      *value = result;
      return true;
    }
    shift += 7;
  }
  return false;
}

bool VarintReader::read_i64(int64_t* value) {
  uint64_t encoded = 0;
  if (!read_u64(&encoded)) return false;
  *value = zigzag_decode(encoded);
  return true;
}

bool VarintReader::read_bytes(const uint8_t** bytes, size_t count) {
  if (remaining() < count) return false;
  *bytes = data_ + pos_;
  pos_ += count;
  return true;
}

size_t VarintReader::remaining() const {
  return size_ - pos_;
}

void append_u64_varint(uint64_t value, std::vector<uint8_t>* out) {
  while (value >= 0x80u) {
    out->push_back(static_cast<uint8_t>(value | 0x80u));
    value >>= 7;
  }
  out->push_back(static_cast<uint8_t>(value));
}

void append_i64_varint(int64_t value, std::vector<uint8_t>* out) {
  append_u64_varint(zigzag_encode(value), out);
}

uint64_t zigzag_encode(int64_t value) {
  return (static_cast<uint64_t>(value) << 1) ^ static_cast<uint64_t>(value >> 63);
}

int64_t zigzag_decode(uint64_t value) {
  return static_cast<int64_t>((value >> 1) ^ (~(value & 1u) + 1u));
}

}  // namespace ledgerframe
