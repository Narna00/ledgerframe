#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace ledgerframe {

struct Frame {
  std::string channel;
  uint64_t timestamp_ms = 0;
  uint16_t flags = 0;
  std::vector<uint8_t> payload;
};

class FrameReader {
 public:
  bool parse_one(const uint8_t* data, size_t size, Frame* frame, size_t* consumed);

 private:
  bool decode_payload(uint8_t codec, uint32_t expected_size,
                      const uint8_t* data, size_t size,
                      std::vector<uint8_t>* out);
};

}  // namespace ledgerframe
