#include "ledgerframe/frame_reader.h"

#include <cstring>

#include "ledgerframe/bitstream.h"
#include "ledgerframe/crc32.h"

namespace ledgerframe {

namespace {
constexpr uint32_t kFrameMagic = 0x31464c44u;  // DLF1
constexpr uint8_t kCodecRaw = 0;
constexpr uint8_t kCodecRle = 1;
constexpr size_t kHeaderSize = 4 + 2 + 8 + 2 + 1 + 1 + 4 + 4 + 4;
}  // namespace

bool FrameReader::parse_one(const uint8_t* data, size_t size, Frame* frame, size_t* consumed) {
  ByteReader reader(data, size);
  uint32_t magic = 0;
  uint16_t channel_len = 0;
  uint64_t timestamp = 0;
  uint16_t flags = 0;
  uint8_t codec = 0;
  uint8_t reserved = 0;
  uint32_t encoded_len = 0;
  uint32_t decoded_len = 0;
  uint32_t expected_crc = 0;

  if (!reader.read_u32(&magic) || magic != kFrameMagic) return false;
  if (!reader.read_u16(&channel_len) || channel_len == 0 || channel_len > 96) return false;
  if (!reader.read_u64(&timestamp)) return false;
  if (!reader.read_u16(&flags)) return false;
  if (!reader.read_u8(&codec) || !reader.read_u8(&reserved) || reserved != 0) return false;
  if (!reader.read_u32(&encoded_len) || !reader.read_u32(&decoded_len)) return false;
  if (!reader.read_u32(&expected_crc)) return false;
  if (encoded_len > reader.remaining()) return false;

  const uint8_t* channel = nullptr;
  if (!reader.read_bytes(&channel, channel_len)) return false;
  const uint8_t* encoded = nullptr;
  if (!reader.read_bytes(&encoded, encoded_len)) return false;

  std::vector<uint8_t> decoded;
  if (!decode_payload(codec, decoded_len, encoded, encoded_len, &decoded)) return false;
  if (crc32(decoded.data(), decoded.size()) != expected_crc) return false;

  frame->channel.assign(reinterpret_cast<const char*>(channel), channel_len);
  frame->timestamp_ms = timestamp;
  frame->flags = flags;
  frame->payload = std::move(decoded);
  *consumed = kHeaderSize + channel_len + encoded_len;
  return true;
}

bool FrameReader::decode_payload(uint8_t codec, uint32_t expected_size,
                                 const uint8_t* data, size_t size,
                                 std::vector<uint8_t>* out) {
  out->clear();
  if (codec == kCodecRaw) {
    if (size != expected_size) return false;
    out->assign(data, data + size);
    return true;
  }

  if (codec != kCodecRle || expected_size > (1u << 20)) return false;
  out->resize(expected_size);
  size_t write_pos = 0;
  ByteReader reader(data, size);
  while (reader.remaining() > 0) {
    uint8_t op = 0;
    if (!reader.read_u8(&op)) return false;
    const uint8_t tag = op >> 6;
    const uint8_t count = op & 0x3fu;
    if (tag == 0) {
      const uint8_t* literal = nullptr;
      if (!reader.read_bytes(&literal, count)) return false;
      std::memcpy(out->data() + write_pos, literal, count);
      write_pos += count;
    } else if (tag == 1) {
      uint8_t value = 0;
      if (!reader.read_u8(&value)) return false;
      std::memset(out->data() + write_pos, value, count + 3);
      write_pos += count + 3;
    } else if (tag == 2) {
      uint8_t low = 0;
      uint8_t high = 0;
      uint8_t run = 0;
      if (!reader.read_u8(&low) || !reader.read_u8(&high) || !reader.read_u8(&run)) return false;
      for (uint8_t i = 0; i < run + 2; ++i) {
        out->data()[write_pos++] = low;
        out->data()[write_pos++] = high;
      }
    } else {
      return false;
    }
  }
  return write_pos == expected_size;
}

}  // namespace ledgerframe
