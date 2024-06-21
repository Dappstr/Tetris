#include "block.hpp"
#include <vector>

Block::Block() :m_cell_size(30), m_rotation_state(0), m_row_offset(0), m_column_offset(0) {
	m_colors = get_cell_colors();
}

void Block::draw(size_t offset_x, size_t offset_y) {

	std::vector<Position> tiles = get_cell_positions();
	for (Position& item : tiles) {
		DrawRectangle(item.get_column() * m_cell_size + offset_x, item.get_row() * m_cell_size + offset_y, m_cell_size - 1, m_cell_size - 1, m_colors[m_id]);
	}
}

void Block::move(size_t rows, size_t columns) {
	m_row_offset += rows;
	m_column_offset += columns;
}

std::vector<Position> Block::get_cell_positions() {
	std::vector<Position> tiles = m_cells[m_rotation_state];
	std::vector<Position> moved_tiles;
	for (auto& item : tiles) {
		Position new_pos = Position(item.get_row() + m_row_offset, item.get_column() + m_column_offset);
		moved_tiles.emplace_back(new_pos);
	}
	return moved_tiles;
}

void Block::rotate() {
	++m_rotation_state;
	if (m_rotation_state == static_cast<int>(m_cells.size())) {
		m_rotation_state = 0;
	}
}

void Block::undo_rotation() {
	--m_rotation_state;
	if (m_rotation_state == -1) {
		m_rotation_state = m_cells.size() - 1;
	}
}