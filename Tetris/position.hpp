#pragma once

class Position {
public:
	Position(const size_t row, const size_t column);
	size_t get_row();
	size_t get_column();

private:
	size_t m_row{}, m_column{};
};