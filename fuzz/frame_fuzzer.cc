#include <cstddef>
#include <cstdint>

#include "ledgerframe/frame_reader.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  ledgerframe::Frame frame;
  size_t consumed = 0;
  ledgerframe::FrameReader reader;
  reader.parse_one(data, size, &frame, &consumed);
  return 0;
}
