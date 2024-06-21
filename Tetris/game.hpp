#pragma once
#include "grid.hpp"
#include "blocks.hpp"

class Game {
public:
	Grid<20, 10> m_grid;
	Game();
	Block get_random_block();
	std::vector<Block> get_all_blocks();
	void draw();
	void handle_input();
	void move_block_left();
	void move_block_right();
	void move_block_down();

	bool game_over;
	size_t m_score{};
private:
	bool is_block_outside();
	void rotate_block();
	void lock_block();
	bool block_fits();
	void reset();
	void update_score(const size_t lines_cleared, const size_t move_down_points);

	std::vector<Block> m_blocks;
	Block m_current_block, m_next_block;
};