#include <cstddef>
#include <cstdint>
#include <string>

#include "ledgerframe/schema.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  std::string schema_text(reinterpret_cast<const char*>(data), size);
  ledgerframe::SchemaRegistry registry;
  std::string error;
  registry.parse_text(schema_text, &error);
  return 0;
}
