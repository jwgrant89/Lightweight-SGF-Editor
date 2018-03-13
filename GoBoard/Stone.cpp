#include "stdafx.h"
#include "Stone.h";

Stone::Stone()
{
	colour = 'N';
}

void Stone::setColour(char newcolour)
{
	colour = newcolour;
}

char Stone::getColour()
{
	return colour;
};

void Stone::draw()
{

};