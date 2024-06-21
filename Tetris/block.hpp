#pragma once
#include <map>
#include <vector>
#include "position.hpp"
#include "colors.hpp"

class Block {
public:
	size_t m_id{};
	Block();

	void draw(size_t offset_x, size_t offset_y);
	void move(size_t rows, size_t columns);
	std::vector<Position> get_cell_positions();
	void rotate();
	void undo_rotation();
	virtual ~Block() = default;

protected:
	std::map<size_t, std::vector<Position>> m_cells;
private:
	size_t m_cell_size{}, m_rotation_state{}, m_row_offset{}, m_column_offset{};
	std::vector<Color> m_colors;

};