#pragma once
struct Location
{
	void Add(const Location& val) { x += val.x; y += val.y; }
	bool operator==(const Location& rhs) const { return x == rhs.x && y == rhs.y; }
	//Location operator=(const Location& rhs) const { Location lhs; lhs.x = rhs.x; lhs.y = rhs.y; return lhs; }
	Location operator+(const Location& rhs) const { Location loc; loc.x = this->x + rhs.x; loc.y = this->y + rhs.y; return loc; }
	int x;
	int y;
};

