#include "Snake.h"

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax) { segments[nSegments].InitBody(); nSegments++; }
}
void Snake::Draw(Board& brd_) const
{
	for (int i = 0; i < nSegments; i++) { segments[i].Draw(brd_); }
}
void Snake::Segment::InitHead(const Location& loc_)
{
	loc = loc_;
	c = Snake::headColor;
}
void Snake::Segment::InitBody()
{
	c = Snake::bodyColor;
}
void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}
void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}
void Snake::Segment::Draw(Board& brd_) const
{
	brd_.DrawCell(loc, c);
}
