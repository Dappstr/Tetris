#include "position.hpp"

Position::Position(const size_t row, const size_t column)
	:m_row(row), m_column(column) {}

size_t Position::get_row() {
	return m_row;
}
size_t Position::get_column() {
	return m_column;
}