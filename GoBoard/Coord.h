#pragma once
#include <SFML/Graphics.hpp>;

#ifndef COORD_H
#define COORD_H
class Coord
{
public:
	int x;
	int y;
	Coord();
	Coord(int x, int y);
	Coord(sf::Vector2i position);
	std::vector<Coord> liberties() const;
	bool operator<(const Coord& other) const;
};

#endif // !COORD_H

