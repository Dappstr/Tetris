#pragma once
#include "block.hpp"
#include "position.hpp"

class LBlock : public Block {
public:
	LBlock();
	~LBlock() = default;
};

class JBlock : public Block {
public:
	JBlock();
	~JBlock() = default;
};

class IBlock : public Block {
public:
	IBlock();
	~IBlock() = default;
};

class OBlock : public Block {
public:
	OBlock();
	~OBlock() = default;
};

class SBlock : public Block {
public:
	SBlock();
	~SBlock() = default;
};

class TBlock : public Block {
public:
	TBlock();
	~TBlock() = default;
};

class ZBlock : public Block {
public:
	ZBlock();
	~ZBlock() = default;
};