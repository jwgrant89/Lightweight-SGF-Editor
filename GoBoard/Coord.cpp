#include "stdafx.h"
#include "Coord.h";

Coord::Coord()
{};
Coord::Coord(int newx, int newy)
{
	x = newx;
	y = newy;
};

Coord::Coord(sf::Vector2i position)
{
	x = position.x;
	y = position.y;
}

std::vector<Coord> Coord::liberties() const
{
	std::vector<Coord> result;
	if (x > 0) result.push_back(Coord(x - 1, y));
	if (x < 18) result.push_back(Coord(x + 1, y));
	if (y > 0) result.push_back(Coord(x, y - 1));
	if (y < 18) result.push_back(Coord(x, y + 1));
	return result;
};

bool Coord::operator<(const Coord& other) const
{
	if (x < other.x) return true;
	if (x == other.x && y < other.y) return true;
	return false;
};