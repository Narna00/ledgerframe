#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "ledgerframe/frame_reader.h"

namespace ledgerframe {

enum class FieldType {
  kInt64,
  kUInt64,
  kDouble,
  kBool,
  kString,
  kBytes,
};

struct FieldDefinition {
  std::string name;
  FieldType type = FieldType::kBytes;
  uint32_t tag = 0;
  bool required = false;
  uint32_t max_length = 0;
};

struct ChannelSchema {
  std::string channel;
  uint32_t version = 1;
  std::vector<FieldDefinition> fields;
};

struct DecodedField {
  std::string name;
  FieldType type = FieldType::kBytes;
  std::string text_value;
  uint64_t unsigned_value = 0;
  int64_t signed_value = 0;
  double double_value = 0.0;
  bool bool_value = false;
  std::vector<uint8_t> bytes_value;
};

class SchemaRegistry {
 public:
  bool parse_text(const std::string& text, std::string* error);
  bool add_schema(const ChannelSchema& schema, std::string* error);
  const ChannelSchema* find(const std::string& channel) const;
  std::vector<std::string> channels() const;

 private:
  static bool parse_field(const std::string& line, FieldDefinition* out, std::string* error);
  static bool parse_type(const std::string& text, FieldType* out);
  static std::string trim(const std::string& text);

  std::map<std::string, ChannelSchema> schemas_;
};

class PayloadDecoder {
 public:
  bool decode(const ChannelSchema& schema, const Frame& frame,
              std::vector<DecodedField>* fields, std::string* error) const;

 private:
  bool decode_one(const FieldDefinition& definition, const uint8_t* data, size_t size,
                  DecodedField* out, std::string* error) const;
};

}  // namespace ledgerframe
