#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "ledgerframe/frame_reader.h"
#include "ledgerframe/schema.h"

namespace ledgerframe {

struct NormalizedRecord {
  std::string channel;
  uint64_t timestamp_ms = 0;
  std::map<std::string, std::string> fields;
};

class Normalizer {
 public:
  explicit Normalizer(SchemaRegistry registry);

  bool normalize(const Frame& frame, NormalizedRecord* record, std::string* error) const;
  std::vector<NormalizedRecord> normalize_many(const std::vector<Frame>& frames) const;
  std::string render_csv(const std::vector<NormalizedRecord>& records) const;

 private:
  static std::string escape_csv(const std::string& value);
  static std::string bytes_to_hex(const std::vector<uint8_t>& bytes);

  SchemaRegistry registry_;
};

class RecordProjector {
 public:
  explicit RecordProjector(std::vector<std::string> columns);
  std::vector<std::string> project(const NormalizedRecord& record) const;
  const std::vector<std::string>& columns() const;

 private:
  std::vector<std::string> columns_;
};

}  // namespace ledgerframe
