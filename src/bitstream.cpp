#include "ledgerframe/bitstream.h"

namespace ledgerframe {

ByteReader::ByteReader(const uint8_t* data, size_t size)
    : data_(data), size_(size), pos_(0) {}

bool ByteReader::read_u8(uint8_t* value) {
  if (remaining() < 1) return false;
  *value = data_[pos_++];
  return true;
}

bool ByteReader::read_u16(uint16_t* value) {
  if (remaining() < 2) return false;
  *value = static_cast<uint16_t>(data_[pos_]) |
           (static_cast<uint16_t>(data_[pos_ + 1]) << 8);
  pos_ += 2;
  return true;
}

bool ByteReader::read_u32(uint32_t* value) {
  if (remaining() < 4) return false;
  *value = static_cast<uint32_t>(data_[pos_]) |
           (static_cast<uint32_t>(data_[pos_ + 1]) << 8) |
           (static_cast<uint32_t>(data_[pos_ + 2]) << 16) |
           (static_cast<uint32_t>(data_[pos_ + 3]) << 24);
  pos_ += 4;
  return true;
}

bool ByteReader::read_u64(uint64_t* value) {
  uint32_t low = 0;
  uint32_t high = 0;
  if (!read_u32(&low) || !read_u32(&high)) return false;
  *value = static_cast<uint64_t>(low) | (static_cast<uint64_t>(high) << 32);
  return true;
}

bool ByteReader::read_bytes(const uint8_t** bytes, size_t count) {
  if (remaining() < count) return false;
  *bytes = data_ + pos_;
  pos_ += count;
  return true;
}

bool ByteReader::skip(size_t count) {
  if (remaining() < count) return false;
  pos_ += count;
  return true;
}

const uint8_t* ByteReader::cursor() const {
  return data_ + pos_;
}

size_t ByteReader::remaining() const {
  return size_ - pos_;
}

size_t ByteReader::offset() const {
  return pos_;
}

}  // namespace ledgerframe
