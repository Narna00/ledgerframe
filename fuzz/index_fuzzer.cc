#include <cstddef>
#include <cstdint>
#include <string>

#include "ledgerframe/index.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  ledgerframe::Index index;
  if (index.parse(data, size) && size > 0) {
    const size_t n = data[0] % 32;
    std::string channel(reinterpret_cast<const char*>(data), reinterpret_cast<const char*>(data) + (n < size ? n : size));
    index.find(channel);
  }
  return 0;
}
