#include "scanner.hpp"

bool Scanner::is_eol() const noexcept {
  return current() == '\n';
}

bool Scanner::is_eof() const noexcept {
  return m_position >= m_source.size();
}

char Scanner::current() const noexcept {
  return is_eof() ? '\0' : m_source[m_position];
}

char Scanner::peek_next(int offset) const noexcept {
  size_t pos = m_position + offset;
  return pos >= m_source.size() ? '\0' : m_source[pos];
}

char Scanner::advance(int offset) noexcept {
  char c = current();

  for (int i = 0; i < offset; i++) {
    if (is_eof()) break;

    if (m_source[m_position] == '\n') {
      m_line++;
      m_column = 1;
    } else {
      m_column++;
    }
    m_position++;
  }

  return c;
}
