#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "ledgerframe/frame_reader.h"
#include "ledgerframe/index.h"

namespace ledgerframe {

struct Batch {
  std::vector<Frame> frames;
  Index index;
};

class BatchReader {
 public:
  bool parse(const uint8_t* data, size_t size, Batch* out);
  std::vector<Frame> select_channel(const Batch& batch, const std::string& channel) const;
};

}  // namespace ledgerframe
