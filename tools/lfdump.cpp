#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

#include "ledgerframe/batch_reader.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "usage: lfdump <batch.lfb>\n";
    return 2;
  }

  std::ifstream in(argv[1], std::ios::binary);
  if (!in) {
    std::cerr << "cannot open input\n";
    return 2;
  }
  std::vector<uint8_t> bytes((std::istreambuf_iterator<char>(in)), {});
  ledgerframe::Batch batch;
  ledgerframe::BatchReader reader;
  if (!reader.parse(bytes.data(), bytes.size(), &batch)) {
    std::cerr << "invalid batch\n";
    return 1;
  }

  for (const auto& frame : batch.frames) {
    std::cout << frame.timestamp_ms << " " << frame.channel << " "
              << frame.payload.size() << " bytes\n";
  }
  return 0;
}
