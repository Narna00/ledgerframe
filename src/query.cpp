#include "ledgerframe/query.h"

#include <cctype>
#include <cstdlib>

namespace ledgerframe {

QueryLexer::QueryLexer(const std::string& source) : source_(source) {}

QueryToken QueryLexer::next() {
  skip_space();
  const char c = peek();
  if (c == '\0') return QueryToken{};
  if (std::isalpha(static_cast<unsigned char>(c)) || c == '_') return identifier();
  if (std::isdigit(static_cast<unsigned char>(c))) return number();
  if (c == '\'' || c == '"') return quoted_string();
  take();
  if (c == '(') return QueryToken{QueryTokenKind::kLParen, "("};
  if (c == ')') return QueryToken{QueryTokenKind::kRParen, ")"};
  if (c == '=' && peek() == '=') {
    take();
    return QueryToken{QueryTokenKind::kEqual, "=="};
  }
  if (c == '!' && peek() == '=') {
    take();
    return QueryToken{QueryTokenKind::kNotEqual, "!="};
  }
  if (c == '<' && peek() == '=') {
    take();
    return QueryToken{QueryTokenKind::kLessEqual, "<="};
  }
  if (c == '>' && peek() == '=') {
    take();
    return QueryToken{QueryTokenKind::kGreaterEqual, ">="};
  }
  if (c == '<') return QueryToken{QueryTokenKind::kLess, "<"};
  if (c == '>') return QueryToken{QueryTokenKind::kGreater, ">"};
  return QueryToken{};
}

char QueryLexer::peek() const {
  return pos_ < source_.size() ? source_[pos_] : '\0';
}

char QueryLexer::take() {
  return pos_ < source_.size() ? source_[pos_++] : '\0';
}

void QueryLexer::skip_space() {
  while (std::isspace(static_cast<unsigned char>(peek()))) take();
}

QueryToken QueryLexer::identifier() {
  std::string text;
  while (std::isalnum(static_cast<unsigned char>(peek())) || peek() == '_' || peek() == '.') {
    text.push_back(take());
  }
  if (text == "and") return QueryToken{QueryTokenKind::kAnd, text};
  if (text == "or") return QueryToken{QueryTokenKind::kOr, text};
  return QueryToken{QueryTokenKind::kIdentifier, text};
}

QueryToken QueryLexer::quoted_string() {
  const char quote = take();
  std::string text;
  while (peek() != '\0' && peek() != quote) {
    const char c = take();
    if (c == '\\' && peek() != '\0') {
      const char escaped = take();
      if (escaped == 'n') text.push_back('\n');
      else if (escaped == 't') text.push_back('\t');
      else text.push_back(escaped);
    } else {
      text.push_back(c);
    }
  }
  if (peek() == quote) take();
  return QueryToken{QueryTokenKind::kString, text};
}

QueryToken QueryLexer::number() {
  std::string text;
  while (std::isdigit(static_cast<unsigned char>(peek())) || peek() == '.') text.push_back(take());
  QueryToken token{QueryTokenKind::kNumber, text};
  token.number = std::strtod(text.c_str(), nullptr);
  return token;
}

int QueryProgram::add_predicate(const QueryPredicate& predicate) {
  Node node;
  node.op = Op::kPredicate;
  node.predicate = predicate;
  nodes_.push_back(node);
  root_ = static_cast<int>(nodes_.size() - 1);
  return root_;
}

int QueryProgram::add_binary(Op op, int left, int right) {
  Node node;
  node.op = op;
  node.left = left;
  node.right = right;
  nodes_.push_back(node);
  root_ = static_cast<int>(nodes_.size() - 1);
  return root_;
}

bool QueryProgram::evaluate(const Frame& frame) const {
  if (root_ < 0) return true;
  return eval_node(root_, frame);
}

bool QueryProgram::empty() const {
  return root_ < 0;
}

const std::vector<QueryProgram::Node>& QueryProgram::nodes() const {
  return nodes_;
}

bool QueryProgram::eval_node(int index, const Frame& frame) const {
  if (index < 0 || static_cast<size_t>(index) >= nodes_.size()) return false;
  const Node& node = nodes_[index];
  if (node.op == Op::kAnd) return eval_node(node.left, frame) && eval_node(node.right, frame);
  if (node.op == Op::kOr) return eval_node(node.left, frame) || eval_node(node.right, frame);

  const QueryPredicate& p = node.predicate;
  std::string string_value;
  double number_value = 0.0;
  bool left_is_string = false;
  switch (p.field) {
    case QueryField::kChannel:
      string_value = frame.channel;
      left_is_string = true;
      break;
    case QueryField::kPayloadText:
      string_value = payload_as_text(frame);
      left_is_string = true;
      break;
    case QueryField::kTimestamp:
      number_value = static_cast<double>(frame.timestamp_ms);
      break;
    case QueryField::kFlags:
      number_value = static_cast<double>(frame.flags);
      break;
    case QueryField::kPayloadSize:
      number_value = static_cast<double>(frame.payload.size());
      break;
  }

  if (left_is_string || p.value_is_string) {
    const int cmp = string_value.compare(p.string_value);
    if (p.compare == QueryCompare::kEqual) return cmp == 0;
    if (p.compare == QueryCompare::kNotEqual) return cmp != 0;
    if (p.compare == QueryCompare::kLess) return cmp < 0;
    if (p.compare == QueryCompare::kLessEqual) return cmp <= 0;
    if (p.compare == QueryCompare::kGreater) return cmp > 0;
    if (p.compare == QueryCompare::kGreaterEqual) return cmp >= 0;
    return false;
  }

  if (p.compare == QueryCompare::kEqual) return number_value == p.number_value;
  if (p.compare == QueryCompare::kNotEqual) return number_value != p.number_value;
  if (p.compare == QueryCompare::kLess) return number_value < p.number_value;
  if (p.compare == QueryCompare::kLessEqual) return number_value <= p.number_value;
  if (p.compare == QueryCompare::kGreater) return number_value > p.number_value;
  if (p.compare == QueryCompare::kGreaterEqual) return number_value >= p.number_value;
  return false;
}

std::string QueryProgram::payload_as_text(const Frame& frame) {
  std::string text;
  text.reserve(frame.payload.size());
  for (uint8_t b : frame.payload) {
    if (b == 0) break;
    text.push_back(static_cast<char>(b));
  }
  return text;
}

bool QueryParser::parse(const std::string& source, QueryProgram* program, std::string* error) {
  lexer_ = QueryLexer(source);
  current_ = lexer_.next();
  error_.clear();
  QueryProgram parsed;
  const int root = parse_or(&parsed);
  if (root < 0 || current_.kind != QueryTokenKind::kEnd) {
    if (error_.empty()) error_ = "invalid query";
    if (error) *error = error_;
    return false;
  }
  *program = parsed;
  return true;
}

int QueryParser::parse_or(QueryProgram* program) {
  int left = parse_and(program);
  while (left >= 0 && accept(QueryTokenKind::kOr)) {
    const int right = parse_and(program);
    if (right < 0) return -1;
    left = program->add_binary(QueryProgram::Op::kOr, left, right);
  }
  return left;
}

int QueryParser::parse_and(QueryProgram* program) {
  int left = parse_primary(program);
  while (left >= 0 && accept(QueryTokenKind::kAnd)) {
    const int right = parse_primary(program);
    if (right < 0) return -1;
    left = program->add_binary(QueryProgram::Op::kAnd, left, right);
  }
  return left;
}

int QueryParser::parse_primary(QueryProgram* program) {
  if (accept(QueryTokenKind::kLParen)) {
    const int node = parse_or(program);
    if (!expect(QueryTokenKind::kRParen)) return -1;
    return node;
  }
  return parse_predicate(program);
}

int QueryParser::parse_predicate(QueryProgram* program) {
  if (current_.kind != QueryTokenKind::kIdentifier) {
    error_ = "expected field name";
    return -1;
  }

  QueryPredicate predicate;
  const std::string field = current_.text;
  if (field == "channel") predicate.field = QueryField::kChannel;
  else if (field == "timestamp") predicate.field = QueryField::kTimestamp;
  else if (field == "flags") predicate.field = QueryField::kFlags;
  else if (field == "payload_size") predicate.field = QueryField::kPayloadSize;
  else if (field == "payload") predicate.field = QueryField::kPayloadText;
  else {
    error_ = "unknown field";
    return -1;
  }
  advance();

  switch (current_.kind) {
    case QueryTokenKind::kEqual: predicate.compare = QueryCompare::kEqual; break;
    case QueryTokenKind::kNotEqual: predicate.compare = QueryCompare::kNotEqual; break;
    case QueryTokenKind::kLess: predicate.compare = QueryCompare::kLess; break;
    case QueryTokenKind::kLessEqual: predicate.compare = QueryCompare::kLessEqual; break;
    case QueryTokenKind::kGreater: predicate.compare = QueryCompare::kGreater; break;
    case QueryTokenKind::kGreaterEqual: predicate.compare = QueryCompare::kGreaterEqual; break;
    default:
      error_ = "expected comparison";
      return -1;
  }
  advance();

  if (current_.kind == QueryTokenKind::kString || current_.kind == QueryTokenKind::kIdentifier) {
    predicate.value_is_string = true;
    predicate.string_value = current_.text;
    advance();
    return program->add_predicate(predicate);
  }
  if (current_.kind == QueryTokenKind::kNumber) {
    predicate.value_is_string = false;
    predicate.number_value = current_.number;
    advance();
    return program->add_predicate(predicate);
  }
  error_ = "expected value";
  return -1;
}

bool QueryParser::accept(QueryTokenKind kind) {
  if (current_.kind != kind) return false;
  advance();
  return true;
}

bool QueryParser::expect(QueryTokenKind kind) {
  if (accept(kind)) return true;
  error_ = "unexpected token";
  return false;
}

void QueryParser::advance() {
  current_ = lexer_.next();
}

}  // namespace ledgerframe
