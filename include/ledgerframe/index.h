#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace ledgerframe {

struct IndexEntry {
  std::string channel;
  uint32_t offset = 0;
  uint32_t length = 0;
};

class Index {
 public:
  bool parse(const uint8_t* data, size_t size);
  std::vector<IndexEntry> find(const std::string& channel) const;
  const std::vector<IndexEntry>& entries() const;

 private:
  std::vector<IndexEntry> entries_;
};

}  // namespace ledgerframe
