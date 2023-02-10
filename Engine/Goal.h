#pragma once
#include "Snake.h"
#include "Board.h"
#include <random>

class Goal
{
public:
	Goal(std::mt19937&, const Board&, const Snake&);
	void Respawn(std::mt19937&, const Board&, const Snake&);
	void Draw(Board&) const;
	Location GetLocation() const { return loc; }
private:
	static constexpr Color c = Colors::Red;
	Location loc;
};

