#pragma once
#include "Coord.h";
#include <SFML/Graphics.hpp>;

#ifndef STONE_H
#define STONE_H
class Stone
{
private:
	char mcolour; // W, B, N, or K
	Coord mposition;
public:
	Stone();
	Stone(char colour, sf::Vector2i position);
	Stone(char colour, Coord coord);
	void setColour(char colour);
	char colour() const;
	Coord coord() const;
	void draw();
};



#endif // !STONE_H

