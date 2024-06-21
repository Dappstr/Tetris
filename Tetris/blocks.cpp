#include "blocks.hpp"

LBlock::LBlock() {
	m_id = 1;
	m_cells[0] = { Position(0,2), Position(1,0), Position(1,1), Position(1,2) };
	m_cells[1] = { Position(0,1), Position(1,1), Position(2,1), Position(2,2) };
	m_cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,0) };
	m_cells[3] = { Position(0,0), Position(0,1), Position(1,1), Position(2,1) };
	move(0, 3);
}

JBlock::JBlock() {
	m_id = 2;
	m_cells[0] = { Position(0,0), Position(1,0), Position(1,1), Position(1,2) };
	m_cells[1] = { Position(0,1), Position(0,2), Position(1,1), Position(2,1) };
	m_cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,2) };
	m_cells[3] = { Position(0,1), Position(1,1), Position(2,0), Position(2,1) };
	move(0, 3);

}

IBlock::IBlock() {
	m_id = 3;
	m_cells[0] = { Position(1,0), Position(1,1), Position(1,2), Position(1,3) };
	m_cells[1] = { Position(0,2), Position(1,2), Position(2,2), Position(3,2) };
	m_cells[2] = { Position(2,0), Position(2,1), Position(2,2), Position(2,3) };
	m_cells[3] = { Position(0,1), Position(1,1), Position(2,1), Position(3,1) };
	move(-1, 3);
}

OBlock::OBlock() {
	m_id = 4;
	m_cells[0] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
	move(0, 4);
}

SBlock::SBlock() {
	m_id = 5;
	m_cells[0] = { Position(0,1), Position(0,2), Position(1,0), Position(1,1) };
	m_cells[1] = { Position(0,1), Position(1,1), Position(1,2), Position(2,2) };
	m_cells[2] = { Position(1,1), Position(1,2), Position(2,0), Position(2,1) };
	m_cells[3] = { Position(0,0), Position(1,0), Position(1,1), Position(2,1) };
	move(0, 3);
}

TBlock::TBlock() {
	m_id = 6;
	m_cells[0] = { Position(0,1), Position(1,0), Position(1,1), Position(1,2) };
	m_cells[1] = { Position(0,1), Position(1,1), Position(1,2), Position(2,1) };
	m_cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,1) };
	m_cells[3] = { Position(0,1), Position(1,0), Position(1,1), Position(2,1) };
	move(0, 3);
}

ZBlock::ZBlock() {
	m_id = 7;
	m_cells[0] = { Position(0,0), Position(0,1), Position(1,1), Position(1,2) };
	m_cells[1] = { Position(0,2), Position(1,1), Position(1,2), Position(2,1) };
	m_cells[2] = { Position(1,0), Position(1,1), Position(2,1), Position(2,2) };
	m_cells[3] = { Position(0,1), Position(1,0), Position(1,1), Position(2,0) };
	move(0, 3);
}