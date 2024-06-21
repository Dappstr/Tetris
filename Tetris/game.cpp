#include "game.hpp"

Game::Game() {
	m_grid = Grid<20, 10>();
	game_over = false;
	m_score = 0;
	m_blocks = get_all_blocks();
	m_current_block = get_random_block();
	m_next_block = get_random_block();
}

Block Game::get_random_block() {
	srand(time(NULL));
	if (m_blocks.empty()) {
		m_blocks = get_all_blocks();
	}
	int random_index = rand() % m_blocks.size();
	Block block = m_blocks[random_index];
	m_blocks.erase(m_blocks.begin() + random_index);
	return block;
}

std::vector<Block> Game::get_all_blocks() {
	return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

void Game::draw() {
	m_grid.draw();
	m_current_block.draw(11, 11);
	m_next_block.draw(255, 350);
}

void Game::handle_input() {
	int key_press = GetKeyPressed();
	if (game_over && key_press != 0) {
		game_over = false;
		reset();
	}
	switch (key_press) {
		case KEY_LEFT:
			move_block_left();
			break;
		case KEY_RIGHT:
			move_block_right();
			break;
		case KEY_DOWN:
			move_block_down();
			update_score(0, 1);
			break;
		case KEY_UP:
			rotate_block();
			break;
	}
}

void Game::move_block_left() {
	if (!game_over) {
		m_current_block.move(0, -1);
		if (this->is_block_outside() || this->block_fits() == false) {
			m_current_block.move(0, 1);
		}
	}
}

void Game::move_block_right() {
	if (!game_over) {
		m_current_block.move(0, 1);
		if (this->is_block_outside() || this->block_fits() == false) {
			m_current_block.move(0, -1);
		}
	}
}

void Game::move_block_down() {
	if (!game_over) {
		m_current_block.move(1, 0);
		if (this->is_block_outside() || block_fits() == false) {
			m_current_block.move(-1, 0);
			lock_block();
		}
	}
}

bool Game::is_block_outside() {
	std::vector<Position> tiles = m_current_block.get_cell_positions();
	for (auto& item : tiles) {
		if (m_grid.is_cell_outside(item.get_row(), item.get_column())) {
			return true;
		}
	}
	return false;
}

void Game::rotate_block() {
	m_current_block.rotate();
	if (is_block_outside() || this->block_fits() == false) {
		m_current_block.undo_rotation();
	}
}

void Game::lock_block() {
	std::vector<Position> tiles = m_current_block.get_cell_positions();
	for (auto& item : tiles) {
		m_grid.m_grid[item.get_row()][item.get_column()] = m_current_block.m_id;
	}
	m_current_block = m_next_block;
	if (block_fits() == false) {
		game_over = true;
	}
	m_next_block = get_random_block();
	m_grid.clear_full_rows();

	int rows_cleared = m_grid.clear_full_rows();
	update_score(rows_cleared, 0);
}

bool Game::block_fits() {
	std::vector<Position> tiles = m_current_block.get_cell_positions();
	for (auto& item : tiles) {
		if (m_grid.is_cell_empty(item.get_row(), item.get_column()) == false) {
			return false;
		}
	}
	return true;
}

void Game::reset() {
	m_grid = Grid<20, 10>();
	m_blocks = get_all_blocks();
	m_current_block = get_random_block();
	m_next_block = get_random_block();
	m_score = 0;
}

void Game::update_score(const size_t lines_cleared, const size_t move_down_points) {
	switch (lines_cleared) {
		case 1:
			m_score += 100;
			break;
		case 2:
			m_score += 300;
			break;
		case 3:
			m_score += 500;
			break;
		[[unlikely]] default:
			break;
	}
	m_score += move_down_points;
}
