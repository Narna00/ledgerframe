#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "ledgerframe/frame_reader.h"
#include "ledgerframe/index.h"

namespace ledgerframe {

enum class PayloadCodec {
  kRaw,
  kRle,
};

struct WriterOptions {
  PayloadCodec codec = PayloadCodec::kRaw;
  bool include_index = true;
  uint32_t max_rle_savings = 8;
};

class FrameWriter {
 public:
  bool encode(const Frame& frame, PayloadCodec codec, std::vector<uint8_t>* out) const;
  static void append_u16(uint16_t value, std::vector<uint8_t>* out);
  static void append_u32(uint32_t value, std::vector<uint8_t>* out);
  static void append_u64(uint64_t value, std::vector<uint8_t>* out);

 private:
  static void encode_rle(const std::vector<uint8_t>& payload, std::vector<uint8_t>* out);
  static void flush_literal(const std::vector<uint8_t>& literal, std::vector<uint8_t>* out);
};

class BatchWriter {
 public:
  explicit BatchWriter(WriterOptions options);
  bool encode(const std::vector<Frame>& frames, std::vector<uint8_t>* out) const;

 private:
  static void append_index(const std::vector<Frame>& frames, std::vector<uint8_t>* out);

  WriterOptions options_;
};

}  // namespace ledgerframe
