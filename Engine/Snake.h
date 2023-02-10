#pragma once
#include "Board.h"
#include <assert.h>

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location&);
		void InitBody();
		void Follow(const Segment&);
		void MoveBy(const Location&);
		void Draw(Board&) const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location&);
	void MoveBy(const Location&);
	void Grow();
	void Draw(Board&) const;
private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Blue;
	static constexpr int nSegmentsMax = 100;
	int nSegments = 1;
	Segment segments[nSegmentsMax];
};

