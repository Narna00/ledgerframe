#include <cstddef>
#include <cstdint>
#include <string>

#include "ledgerframe/query.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  std::string query(reinterpret_cast<const char*>(data), size);
  ledgerframe::QueryProgram program;
  ledgerframe::QueryParser parser;
  std::string error;
  parser.parse(query, &program, &error);
  return 0;
}
