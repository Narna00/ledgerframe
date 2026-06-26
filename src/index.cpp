#include "ledgerframe/index.h"

#include "ledgerframe/bitstream.h"

namespace ledgerframe {

bool Index::parse(const uint8_t* data, size_t size) {
  entries_.clear();
  ByteReader reader(data, size);
  uint32_t count = 0;
  if (!reader.read_u32(&count) || count > 4096) return false;

  for (uint32_t i = 0; i < count; ++i) {
    uint8_t channel_len = 0;
    uint32_t offset = 0;
    uint32_t length = 0;
    if (!reader.read_u8(&channel_len) || channel_len == 0 || channel_len > 96) return false;
    if (!reader.read_u32(&offset) || !reader.read_u32(&length)) return false;
    const uint8_t* channel = nullptr;
    if (!reader.read_bytes(&channel, channel_len)) return false;
    IndexEntry entry;
    entry.channel.assign(reinterpret_cast<const char*>(channel), channel_len);
    entry.offset = offset;
    entry.length = length;
    entries_.push_back(entry);
  }
  return reader.remaining() == 0;
}

std::vector<IndexEntry> Index::find(const std::string& channel) const {
  std::vector<IndexEntry> matches;
  for (const auto& entry : entries_) {
    if (entry.channel == channel) matches.push_back(entry);
  }
  return matches;
}

const std::vector<IndexEntry>& Index::entries() const {
  return entries_;
}

}  // namespace ledgerframe
