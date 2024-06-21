#pragma once
#include <array>
#include <iostream>
#include <vector>
#include <raylib.h>
#include "colors.hpp"

template <size_t R, size_t C>
class Grid {
public:
	std::array<std::array<size_t, C>, R> m_grid{};
	
	Grid();
	void print();
	void draw();
	void set_index(const size_t row, const size_t column, const size_t value);
	bool is_cell_outside(size_t row, size_t column);
	bool is_cell_empty(const size_t row, const size_t column);
	int clear_full_rows();

private:
	bool is_row_full(const size_t row);
	void clear_row(const size_t row);
	void move_row_down(const size_t row, const size_t num_rows);
	size_t m_cell_size{};
	std::vector<Color> m_colors{};
};

template <size_t R, size_t C>
Grid<R, C>::Grid() :m_cell_size(30) {
	for (auto& row : m_grid) {
		row.fill(0);
	}
	m_colors = get_cell_colors();
}

template <size_t R, size_t C>
void Grid<R, C>::print() {
	for (size_t row = 0; row < R; ++row) {
		for (size_t column = 0; column < C; ++column) {
			std::cout << m_grid.at(row).at(column) << ' ';
		}
		std::cout << '\n';
	}
}

template <size_t R, size_t C>
void Grid<R, C>::draw() {
	for (size_t row = 0; row < R; ++row) {
		for (size_t column = 0; column < C; ++column) {
			size_t cell_value = m_grid.at(row).at(column);
			DrawRectangle(column * m_cell_size + 11, row * m_cell_size + 11, m_cell_size - 1, m_cell_size - 1, m_colors.at(cell_value));
		}
	}
}

template <size_t R, size_t C>
void Grid<R, C>::set_index(const size_t row, const size_t column, const size_t value) {
	this->m_grid.at(row).at(column) = value;
}

template <size_t R, size_t C>
bool Grid<R, C>::is_cell_outside(size_t row, size_t column) {
	if (row >= 0 && row < R && column >= 0 && column < C) {
		return false;
	}
	return true;
}

template <size_t R, size_t C>
bool Grid<R, C>::is_cell_empty(const size_t row, const size_t column) {
	if (m_grid[row][column] == 0) {
		return true;
	}
	return false;
}

template <size_t R, size_t C>
int Grid<R, C>::clear_full_rows() {
	int completed = 0;
	for (int row = R - 1; row >= 0; --row) {
		if (is_row_full(row)) {
			clear_row(row);
			++completed;
		}
		else if (completed > 0) {
			move_row_down(row, completed);
		}
	}
	return completed;
}

template <size_t R, size_t C>
bool Grid<R, C>::is_row_full(const size_t row) {
	for (size_t column = 0; column < C; ++column) {
		if (m_grid[row][column] == 0) {
			return false;
		}
	}
	return true;
}


template <size_t R, size_t C>
void Grid<R, C>::clear_row(const size_t row) {
	for (size_t column = 0; column < C; ++column) {
		m_grid[row][column] = 0;
	}
}

template <size_t R, size_t C>
void Grid<R, C>::move_row_down(const size_t row, const size_t num_rows) {
	for (size_t column = 0; column < C; ++column) {
		m_grid[row + num_rows][column] = m_grid[row][column];
		m_grid[row][column] = 0;
	}
}