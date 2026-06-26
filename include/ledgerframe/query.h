#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "ledgerframe/frame_reader.h"

namespace ledgerframe {

enum class QueryTokenKind {
  kEnd,
  kIdentifier,
  kString,
  kNumber,
  kEqual,
  kNotEqual,
  kLess,
  kLessEqual,
  kGreater,
  kGreaterEqual,
  kAnd,
  kOr,
  kLParen,
  kRParen,
};

struct QueryToken {
  QueryTokenKind kind = QueryTokenKind::kEnd;
  std::string text;
  double number = 0.0;
};

class QueryLexer {
 public:
  explicit QueryLexer(const std::string& source);
  QueryToken next();

 private:
  char peek() const;
  char take();
  void skip_space();
  QueryToken identifier();
  QueryToken quoted_string();
  QueryToken number();

  std::string source_;
  size_t pos_ = 0;
};

enum class QueryField {
  kChannel,
  kTimestamp,
  kFlags,
  kPayloadSize,
  kPayloadText,
};

enum class QueryCompare {
  kEqual,
  kNotEqual,
  kLess,
  kLessEqual,
  kGreater,
  kGreaterEqual,
};

struct QueryPredicate {
  QueryField field = QueryField::kChannel;
  QueryCompare compare = QueryCompare::kEqual;
  std::string string_value;
  double number_value = 0.0;
  bool value_is_string = false;
};

class QueryProgram {
 public:
  enum class Op {
    kPredicate,
    kAnd,
    kOr,
  };

  struct Node {
    Op op = Op::kPredicate;
    QueryPredicate predicate;
    int left = -1;
    int right = -1;
  };

  int add_predicate(const QueryPredicate& predicate);
  int add_binary(Op op, int left, int right);
  bool evaluate(const Frame& frame) const;
  bool empty() const;
  const std::vector<Node>& nodes() const;

 private:
  bool eval_node(int index, const Frame& frame) const;
  static std::string payload_as_text(const Frame& frame);

  std::vector<Node> nodes_;
  int root_ = -1;
};

class QueryParser {
 public:
  bool parse(const std::string& source, QueryProgram* program, std::string* error);

 private:
  int parse_or(QueryProgram* program);
  int parse_and(QueryProgram* program);
  int parse_primary(QueryProgram* program);
  int parse_predicate(QueryProgram* program);
  bool accept(QueryTokenKind kind);
  bool expect(QueryTokenKind kind);
  void advance();

  QueryLexer lexer_{""};
  QueryToken current_;
  std::string error_;
};

}  // namespace ledgerframe
