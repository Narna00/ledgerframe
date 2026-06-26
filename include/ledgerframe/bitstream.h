#pragma once

#include <cstddef>
#include <cstdint>

namespace ledgerframe {

class ByteReader {
 public:
  ByteReader(const uint8_t* data, size_t size);

  bool read_u8(uint8_t* value);
  bool read_u16(uint16_t* value);
  bool read_u32(uint32_t* value);
  bool read_u64(uint64_t* value);
  bool read_bytes(const uint8_t** bytes, size_t count);
  bool skip(size_t count);

  const uint8_t* cursor() const;
  size_t remaining() const;
  size_t offset() const;

 private:
  const uint8_t* data_;
  size_t size_;
  size_t pos_;
};

}  // namespace ledgerframe
