#include "stdafx.h"
#include "Stone.h";

Stone::Stone()
{
	mcolour = 'N';
}

Stone::Stone(char colour, sf::Vector2i position)
{
	mcolour = colour;
	mposition = Coord(position);
}

Stone::Stone(char colour, Coord coord)
{
	mcolour = colour;
	mposition = coord;
}

void Stone::setColour(char newcolour)
{
	mcolour = newcolour;
}

char Stone::colour() const
{
	return mcolour;
};

Coord Stone::coord() const
{
	return mposition;
}

void Stone::draw()
{

};