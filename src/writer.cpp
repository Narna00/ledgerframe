#include "ledgerframe/writer.h"

#include <algorithm>
#include <cstddef>
#include <map>
#include <utility>

#include "ledgerframe/crc32.h"

namespace ledgerframe {

namespace {
constexpr uint32_t kFrameMagic = 0x31464c44u;
constexpr uint32_t kBatchMagic = 0x3142464cu;
}

bool FrameWriter::encode(const Frame& frame, PayloadCodec codec, std::vector<uint8_t>* out) const {
  if (frame.channel.empty() || frame.channel.size() > 96 || frame.payload.size() > (1u << 20)) return false;

  std::vector<uint8_t> encoded;
  uint8_t codec_byte = 0;
  if (codec == PayloadCodec::kRaw) {
    encoded = frame.payload;
    codec_byte = 0;
  } else {
    encode_rle(frame.payload, &encoded);
    codec_byte = 1;
  }

  out->clear();
  append_u32(kFrameMagic, out);
  append_u16(static_cast<uint16_t>(frame.channel.size()), out);
  append_u64(frame.timestamp_ms, out);
  append_u16(frame.flags, out);
  out->push_back(codec_byte);
  out->push_back(0);
  append_u32(static_cast<uint32_t>(encoded.size()), out);
  append_u32(static_cast<uint32_t>(frame.payload.size()), out);
  append_u32(crc32(frame.payload.data(), frame.payload.size()), out);
  out->insert(out->end(), frame.channel.begin(), frame.channel.end());
  out->insert(out->end(), encoded.begin(), encoded.end());
  return true;
}

void FrameWriter::append_u16(uint16_t value, std::vector<uint8_t>* out) {
  out->push_back(static_cast<uint8_t>(value));
  out->push_back(static_cast<uint8_t>(value >> 8));
}

void FrameWriter::append_u32(uint32_t value, std::vector<uint8_t>* out) {
  for (int i = 0; i < 4; ++i) out->push_back(static_cast<uint8_t>(value >> (i * 8)));
}

void FrameWriter::append_u64(uint64_t value, std::vector<uint8_t>* out) {
  for (int i = 0; i < 8; ++i) out->push_back(static_cast<uint8_t>(value >> (i * 8)));
}

void FrameWriter::encode_rle(const std::vector<uint8_t>& payload, std::vector<uint8_t>* out) {
  out->clear();
  std::vector<uint8_t> literal;
  size_t pos = 0;
  while (pos < payload.size()) {
    size_t run = 1;
    while (pos + run < payload.size() && payload[pos + run] == payload[pos] && run < 66) ++run;
    if (run >= 3) {
      flush_literal(literal, out);
      out->push_back(static_cast<uint8_t>(0x40u | static_cast<uint8_t>(run - 3)));
      out->push_back(payload[pos]);
      pos += run;
      continue;
    }

    if (pos + 5 < payload.size() && payload[pos] == payload[pos + 2] &&
        payload[pos + 1] == payload[pos + 3]) {
      size_t pairs = 2;
      while (pos + pairs * 2 + 1 < payload.size() &&
             payload[pos] == payload[pos + pairs * 2] &&
             payload[pos + 1] == payload[pos + pairs * 2 + 1] && pairs < 65) {
        ++pairs;
      }
      if (pairs >= 3) {
        flush_literal(literal, out);
        out->push_back(static_cast<uint8_t>(0x80u | static_cast<uint8_t>(pairs - 2)));
        out->push_back(payload[pos]);
        out->push_back(payload[pos + 1]);
        pos += pairs * 2;
        continue;
      }
    }

    literal.push_back(payload[pos++]);
    if (literal.size() == 63) flush_literal(literal, out);
  }
  flush_literal(literal, out);
}

void FrameWriter::flush_literal(const std::vector<uint8_t>& literal, std::vector<uint8_t>* out) {
  size_t pos = 0;
  while (pos < literal.size()) {
    const size_t count = std::min<size_t>(literal.size() - pos, 63);
    out->push_back(static_cast<uint8_t>(count));
    out->insert(out->end(), literal.begin() + static_cast<std::ptrdiff_t>(pos),
                literal.begin() + static_cast<std::ptrdiff_t>(pos + count));
    pos += count;
  }
}

BatchWriter::BatchWriter(WriterOptions options) : options_(options) {}

bool BatchWriter::encode(const std::vector<Frame>& frames, std::vector<uint8_t>* out) const {
  if (frames.size() > 8192) return false;
  out->clear();
  FrameWriter frame_writer;
  std::vector<std::vector<uint8_t>> encoded_frames;
  encoded_frames.reserve(frames.size());
  for (const auto& frame : frames) {
    std::vector<uint8_t> encoded;
    if (!frame_writer.encode(frame, options_.codec, &encoded)) return false;
    encoded_frames.push_back(std::move(encoded));
  }

  std::vector<uint8_t> index;
  if (options_.include_index) append_index(frames, &index);

  FrameWriter::append_u32(kBatchMagic, out);
  FrameWriter::append_u32(static_cast<uint32_t>(frames.size()), out);
  FrameWriter::append_u32(static_cast<uint32_t>(index.size()), out);
  out->insert(out->end(), index.begin(), index.end());
  for (const auto& encoded : encoded_frames) out->insert(out->end(), encoded.begin(), encoded.end());
  return true;
}

void BatchWriter::append_index(const std::vector<Frame>& frames, std::vector<uint8_t>* out) {
  std::map<std::string, std::pair<uint32_t, uint32_t>> ranges;
  for (uint32_t i = 0; i < frames.size(); ++i) {
    auto& range = ranges[frames[i].channel];
    if (range.second == 0) range.first = i;
    range.second += 1;
  }

  FrameWriter::append_u32(static_cast<uint32_t>(ranges.size()), out);
  for (const auto& item : ranges) {
    const std::string& channel = item.first;
    if (channel.size() > 255) continue;
    out->push_back(static_cast<uint8_t>(channel.size()));
    FrameWriter::append_u32(item.second.first, out);
    FrameWriter::append_u32(item.second.second, out);
    out->insert(out->end(), channel.begin(), channel.end());
  }
}

}  // namespace ledgerframe
