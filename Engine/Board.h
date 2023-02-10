#pragma once
#include "Graphics.h"
#include "Location.h"
#include <assert.h>

class Board
{
public:
	Board(Graphics& gfx_);
	void DrawCell(const Location& loc, Color c);
	void DrawRect(int x0, int y0, int x1, int y1, Color c);
	void DrawRectDim(int x0, int y0, int width, int height, Color c);
	int GetGridWidth() const { return width; }
	int GetGridHeight() const { return height; }
	bool IsInsideBoard(const Location&) const;
private:
	static constexpr int dimension = 20;
	static constexpr int width = 25;
	static constexpr int height = 25;
	Graphics& gfx;

};

