#pragma once
#include <SFML/Graphics.hpp>;

#ifndef STONE_H
#define STONE_H
class Stone
{
private:
	char colour; // W, B, N, or K
	sf::CircleShape stone;
public:
	Stone();
	void setColour(char colour);
	char getColour();
	void draw();
};



#endif // !STONE_H

