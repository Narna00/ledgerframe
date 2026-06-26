#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include "ledgerframe/batch_reader.h"
#include "ledgerframe/frame_reader.h"

namespace ledgerframe {

struct RepairEvent {
  enum class Kind {
    kSkippedByte,
    kRecoveredFrame,
    kInvalidFrame,
  };

  Kind kind = Kind::kSkippedByte;
  size_t offset = 0;
  size_t length = 0;
  std::string message;
};

class FrameScanner {
 public:
  std::vector<Frame> scan(const uint8_t* data, size_t size, std::vector<RepairEvent>* events) const;

 private:
  static bool looks_like_frame_magic(const uint8_t* data, size_t size, size_t offset);
};

class BatchRepair {
 public:
  bool rebuild_batch(const uint8_t* data, size_t size, Batch* batch, std::vector<RepairEvent>* events) const;
  std::string summarize(const std::vector<RepairEvent>& events) const;
};

}  // namespace ledgerframe
