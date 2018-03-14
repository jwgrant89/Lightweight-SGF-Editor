#pragma once
#include <SFML/Graphics.hpp>;

#ifndef STONE_H
#define STONE_H
class Stone
{
private:
	char mcolour; // W, B, N, or K
	sf::Vector2i mposition;
public:
	Stone();
	Stone(char colour, sf::Vector2i position);
	void setColour(char colour);
	char getColour();
	void draw();
};



#endif // !STONE_H

