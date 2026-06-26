#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

namespace ledgerframe {

class VarintReader {
 public:
  VarintReader(const uint8_t* data, size_t size);

  bool read_u64(uint64_t* value);
  bool read_i64(int64_t* value);
  bool read_bytes(const uint8_t** bytes, size_t count);
  size_t remaining() const;

 private:
  const uint8_t* data_;
  size_t size_;
  size_t pos_;
};

void append_u64_varint(uint64_t value, std::vector<uint8_t>* out);
void append_i64_varint(int64_t value, std::vector<uint8_t>* out);
uint64_t zigzag_encode(int64_t value);
int64_t zigzag_decode(uint64_t value);

}  // namespace ledgerframe
