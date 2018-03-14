#include "stdafx.h"
#include "Stone.h";

Stone::Stone()
{
	mcolour = 'N';
}

Stone::Stone(char colour, sf::Vector2i position)
{
	mcolour = colour;
	mposition = position;
}

void Stone::setColour(char newcolour)
{
	mcolour = newcolour;
}

char Stone::getColour()
{
	return mcolour;
};

void Stone::draw()
{

};