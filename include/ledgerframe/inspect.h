#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "ledgerframe/batch_reader.h"
#include "ledgerframe/catalog.h"

namespace ledgerframe {

struct IntegrityIssue {
  enum class Severity {
    kInfo,
    kWarning,
    kError,
  };

  Severity severity = Severity::kInfo;
  std::string channel;
  uint64_t timestamp_ms = 0;
  std::string message;
};

struct InspectionReport {
  uint64_t frames = 0;
  uint64_t payload_bytes = 0;
  uint64_t channels = 0;
  uint64_t first_timestamp_ms = 0;
  uint64_t last_timestamp_ms = 0;
  std::vector<IntegrityIssue> issues;
  ChannelCatalog catalog;
};

class BatchInspector {
 public:
  InspectionReport inspect(const Batch& batch) const;
  std::string render_report(const InspectionReport& report) const;
  std::string render_json_summary(const InspectionReport& report) const;

 private:
  void check_frame_order(const Batch& batch, InspectionReport* report) const;
  void check_channel_names(const Batch& batch, InspectionReport* report) const;
  void add_issue(InspectionReport* report, IntegrityIssue::Severity severity,
                 const Frame& frame, const std::string& message) const;
};

class PayloadPreview {
 public:
  explicit PayloadPreview(size_t limit);
  std::string preview(const Frame& frame) const;

 private:
  static char printable(uint8_t value);
  size_t limit_;
};

class IssueCounter {
 public:
  void observe(const IntegrityIssue& issue);
  uint64_t infos() const;
  uint64_t warnings() const;
  uint64_t errors() const;

 private:
  uint64_t infos_ = 0;
  uint64_t warnings_ = 0;
  uint64_t errors_ = 0;
};

}  // namespace ledgerframe
