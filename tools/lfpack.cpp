#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

#include "ledgerframe/crc32.h"

namespace {

void put_u16(std::ostream& out, uint16_t value) {
  out.put(static_cast<char>(value & 0xff));
  out.put(static_cast<char>((value >> 8) & 0xff));
}

void put_u32(std::ostream& out, uint32_t value) {
  for (int i = 0; i < 4; ++i) out.put(static_cast<char>((value >> (i * 8)) & 0xff));
}

void put_u64(std::ostream& out, uint64_t value) {
  for (int i = 0; i < 8; ++i) out.put(static_cast<char>((value >> (i * 8)) & 0xff));
}

}  // namespace

int main(int argc, char** argv) {
  if (argc != 5) {
    std::cerr << "usage: lfpack <channel> <timestamp-ms> <payload> <out.lfb>\n";
    return 2;
  }

  const std::string channel = argv[1];
  const uint64_t timestamp = std::stoull(argv[2]);
  const std::string payload = argv[3];
  std::ofstream out(argv[4], std::ios::binary);
  if (!out) return 2;

  put_u32(out, 0x3142464c);
  put_u32(out, 1);
  put_u32(out, 0);

  put_u32(out, 0x31464c44);
  put_u16(out, static_cast<uint16_t>(channel.size()));
  put_u64(out, timestamp);
  put_u16(out, 0);
  out.put(0);
  out.put(0);
  put_u32(out, static_cast<uint32_t>(payload.size()));
  put_u32(out, static_cast<uint32_t>(payload.size()));
  put_u32(out, ledgerframe::crc32(reinterpret_cast<const uint8_t*>(payload.data()), payload.size()));
  out.write(channel.data(), static_cast<std::streamsize>(channel.size()));
  out.write(payload.data(), static_cast<std::streamsize>(payload.size()));
  return 0;
}
