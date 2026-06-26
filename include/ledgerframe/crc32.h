#pragma once

#include <cstddef>
#include <cstdint>

namespace ledgerframe {

uint32_t crc32(const uint8_t* data, size_t size);

}  // namespace ledgerframe
