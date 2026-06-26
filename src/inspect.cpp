#include "ledgerframe/inspect.h"

#include <iomanip>
#include <sstream>
#include <utility>

namespace ledgerframe {

InspectionReport BatchInspector::inspect(const Batch& batch) const {
  InspectionReport report;
  report.frames = batch.frames.size();
  for (const auto& frame : batch.frames) {
    report.payload_bytes += frame.payload.size();
    report.catalog.observe(frame);
    if (report.first_timestamp_ms == 0 || frame.timestamp_ms < report.first_timestamp_ms) {
      report.first_timestamp_ms = frame.timestamp_ms;
    }
    if (frame.timestamp_ms > report.last_timestamp_ms) report.last_timestamp_ms = frame.timestamp_ms;
  }
  report.channels = report.catalog.list().size();
  check_frame_order(batch, &report);
  check_channel_names(batch, &report);
  return report;
}

std::string BatchInspector::render_report(const InspectionReport& report) const {
  std::ostringstream out;
  out << "frames: " << report.frames << '\n';
  out << "channels: " << report.channels << '\n';
  out << "payload_bytes: " << report.payload_bytes << '\n';
  out << "first_timestamp_ms: " << report.first_timestamp_ms << '\n';
  out << "last_timestamp_ms: " << report.last_timestamp_ms << '\n';
  out << "catalog:\n" << report.catalog.render_text();
  if (!report.issues.empty()) {
    out << "issues:\n";
    for (const auto& issue : report.issues) {
      const char* severity = "info";
      if (issue.severity == IntegrityIssue::Severity::kWarning) severity = "warning";
      if (issue.severity == IntegrityIssue::Severity::kError) severity = "error";
      out << severity << ' ' << issue.channel << ' ' << issue.timestamp_ms
          << ' ' << issue.message << '\n';
    }
  }
  return out.str();
}

std::string BatchInspector::render_json_summary(const InspectionReport& report) const {
  IssueCounter counter;
  for (const auto& issue : report.issues) counter.observe(issue);
  std::ostringstream out;
  out << "{";
  out << "\"frames\":" << report.frames << ",";
  out << "\"channels\":" << report.channels << ",";
  out << "\"payload_bytes\":" << report.payload_bytes << ",";
  out << "\"first_timestamp_ms\":" << report.first_timestamp_ms << ",";
  out << "\"last_timestamp_ms\":" << report.last_timestamp_ms << ",";
  out << "\"infos\":" << counter.infos() << ",";
  out << "\"warnings\":" << counter.warnings() << ",";
  out << "\"errors\":" << counter.errors();
  out << "}";
  return out.str();
}

void BatchInspector::check_frame_order(const Batch& batch, InspectionReport* report) const {
  uint64_t last = 0;
  for (const auto& frame : batch.frames) {
    if (last != 0 && frame.timestamp_ms < last) {
      add_issue(report, IntegrityIssue::Severity::kWarning, frame, "timestamp moved backward");
    }
    last = frame.timestamp_ms;
  }
}

void BatchInspector::check_channel_names(const Batch& batch, InspectionReport* report) const {
  for (const auto& frame : batch.frames) {
    if (frame.channel.empty()) {
      add_issue(report, IntegrityIssue::Severity::kError, frame, "empty channel");
      continue;
    }
    if (frame.channel.front() == '.' || frame.channel.back() == '.') {
      add_issue(report, IntegrityIssue::Severity::kWarning, frame, "channel has empty component");
    }
    for (char c : frame.channel) {
      const bool ok = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
                      (c >= '0' && c <= '9') || c == '_' || c == '.' || c == '-';
      if (!ok) {
        add_issue(report, IntegrityIssue::Severity::kWarning, frame, "channel contains unusual character");
        break;
      }
    }
  }
}

void BatchInspector::add_issue(InspectionReport* report, IntegrityIssue::Severity severity,
                               const Frame& frame, const std::string& message) const {
  IntegrityIssue issue;
  issue.severity = severity;
  issue.channel = frame.channel;
  issue.timestamp_ms = frame.timestamp_ms;
  issue.message = message;
  report->issues.push_back(std::move(issue));
}

PayloadPreview::PayloadPreview(size_t limit) : limit_(limit) {}

std::string PayloadPreview::preview(const Frame& frame) const {
  std::ostringstream out;
  out << frame.channel << '@' << frame.timestamp_ms << ' ';
  const size_t n = frame.payload.size() < limit_ ? frame.payload.size() : limit_;
  for (size_t i = 0; i < n; ++i) out << printable(frame.payload[i]);
  if (frame.payload.size() > n) out << "...";
  out << " (" << frame.payload.size() << " bytes)";
  return out.str();
}

char PayloadPreview::printable(uint8_t value) {
  if (value >= 32 && value <= 126) return static_cast<char>(value);
  return '.';
}

void IssueCounter::observe(const IntegrityIssue& issue) {
  if (issue.severity == IntegrityIssue::Severity::kInfo) ++infos_;
  else if (issue.severity == IntegrityIssue::Severity::kWarning) ++warnings_;
  else if (issue.severity == IntegrityIssue::Severity::kError) ++errors_;
}

uint64_t IssueCounter::infos() const {
  return infos_;
}

uint64_t IssueCounter::warnings() const {
  return warnings_;
}

uint64_t IssueCounter::errors() const {
  return errors_;
}

}  // namespace ledgerframe
