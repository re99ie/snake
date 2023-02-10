#include "Board.h"

Board::Board(Graphics& gfx_)
	:
	gfx(gfx_)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
}

void Board::DrawRect(int x0, int y0, int x1, int y1, Color c)
{
	if (x0 > x1) { std::swap(x0, x1); }
	if (y0 > y1) { std::swap(y0, y1); }
	if (x0 < 0) { x0 = 0; }
	if (y0 < 0) { y0 = 0; }
	if (x1 > gfx.ScreenWidth) { x1 = gfx.ScreenWidth; }
	if (y1 > gfx.ScreenHeight) { y1 = gfx.ScreenHeight; }
	for (int i = 0; i < x1 - x0; i++)
	{
		for (int k = 0; k < y1 - y0; k++)
		{
			gfx.PutPixel(x0 + i, y0 + k, c);
		}
	}
}

void Board::DrawRectDim(int x0, int y0, int width, int height, Color c)
{
	DrawRect(x0, y0, x0 + width, y0 + height, c);
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x <= width &&
		loc.y >= 0 && loc.y <= height;
}
