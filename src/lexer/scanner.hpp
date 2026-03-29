#pragma once

#include <cstddef>
#include <string>

class Scanner {
  size_t m_position;
  int m_line, m_column;
  const std::string& m_source;

public:
  bool is_eol() const noexcept;
  bool is_eof() const noexcept;

  char current() const noexcept;
  char advance(int offset = 1) noexcept;
  char peek_next(int offset = 1) const noexcept;

  int line() const noexcept { return m_line; }
  int column() const noexcept { return m_column; }
  size_t position() const noexcept { return m_position; }

  explicit Scanner(const std::string& source) noexcept
      : m_source(source), m_position(0), m_line(1), m_column(1) {}
};
