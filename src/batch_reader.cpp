#include "ledgerframe/batch_reader.h"

#include "ledgerframe/bitstream.h"

namespace ledgerframe {

namespace {
constexpr uint32_t kBatchMagic = 0x3142464cu;  // LFB1
constexpr size_t kMaxFrames = 8192;
}  // namespace

bool BatchReader::parse(const uint8_t* data, size_t size, Batch* out) {
  out->frames.clear();
  ByteReader reader(data, size);
  uint32_t magic = 0;
  uint32_t frame_count = 0;
  uint32_t index_size = 0;
  if (!reader.read_u32(&magic) || magic != kBatchMagic) return false;
  if (!reader.read_u32(&frame_count) || frame_count > kMaxFrames) return false;
  if (!reader.read_u32(&index_size) || index_size > reader.remaining()) return false;

  const uint8_t* index_bytes = nullptr;
  if (!reader.read_bytes(&index_bytes, index_size)) return false;
  if (index_size > 0 && !out->index.parse(index_bytes, index_size)) return false;

  FrameReader frame_reader;
  for (uint32_t i = 0; i < frame_count; ++i) {
    Frame frame;
    size_t consumed = 0;
    if (!frame_reader.parse_one(reader.cursor(), reader.remaining(), &frame, &consumed)) return false;
    if (!reader.skip(consumed)) return false;
    out->frames.push_back(std::move(frame));
  }
  return true;
}

std::vector<Frame> BatchReader::select_channel(const Batch& batch, const std::string& channel) const {
  std::vector<Frame> selected;
  const auto indexed = batch.index.find(channel);
  if (!indexed.empty()) {
    for (const auto& entry : indexed) {
      const uint64_t end = static_cast<uint64_t>(entry.offset) + entry.length;
      for (uint64_t i = entry.offset; i < end; ++i) {
        if (batch.frames[i].channel == channel) selected.push_back(batch.frames[i]);
      }
    }
    return selected;
  }

  for (const auto& frame : batch.frames) {
    if (frame.channel == channel) selected.push_back(frame);
  }
  return selected;
}

}  // namespace ledgerframe
