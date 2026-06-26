#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

#include "ledgerframe/batch_reader.h"
#include "ledgerframe/crc32.h"

namespace {

void append_u16(std::vector<uint8_t>& out, uint16_t value) {
  out.push_back(static_cast<uint8_t>(value));
  out.push_back(static_cast<uint8_t>(value >> 8));
}

void append_u32(std::vector<uint8_t>& out, uint32_t value) {
  for (int i = 0; i < 4; ++i) out.push_back(static_cast<uint8_t>(value >> (i * 8)));
}

void append_u64(std::vector<uint8_t>& out, uint64_t value) {
  for (int i = 0; i < 8; ++i) out.push_back(static_cast<uint8_t>(value >> (i * 8)));
}

std::vector<uint8_t> one_frame_batch(const std::string& channel, const std::string& payload) {
  std::vector<uint8_t> out;
  append_u32(out, 0x3142464c);
  append_u32(out, 1);
  append_u32(out, 0);
  append_u32(out, 0x31464c44);
  append_u16(out, static_cast<uint16_t>(channel.size()));
  append_u64(out, 42);
  append_u16(out, 0);
  out.push_back(0);
  out.push_back(0);
  append_u32(out, static_cast<uint32_t>(payload.size()));
  append_u32(out, static_cast<uint32_t>(payload.size()));
  append_u32(out, ledgerframe::crc32(reinterpret_cast<const uint8_t*>(payload.data()), payload.size()));
  out.insert(out.end(), channel.begin(), channel.end());
  out.insert(out.end(), payload.begin(), payload.end());
  return out;
}

}  // namespace

int main() {
  const auto bytes = one_frame_batch("meter.power", "37.5");
  ledgerframe::Batch batch;
  ledgerframe::BatchReader reader;
  assert(reader.parse(bytes.data(), bytes.size(), &batch));
  assert(batch.frames.size() == 1);
  assert(batch.frames[0].channel == "meter.power");
  assert(batch.frames[0].payload.size() == 4);
  assert(reader.select_channel(batch, "meter.power").size() == 1);
  return 0;
}
