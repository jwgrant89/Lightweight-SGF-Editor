#include "stdafx.h"
#include "Board.h";
#include <iostream>;

Board::Board(sf::Vector2i dimensions) : mboardwidth(dimensions.x), mboardheight(dimensions.y)
{
	// initialise mColours
	char ** boardstate = new char *[mboardheight];
	for (int i = 0;i < mboardheight;i++)
	{
		boardstate[i] = new char[mboardwidth];
	}
	for (int i = 0;i < mboardheight;i++)
	{
		for (int j = 0;j < mboardwidth;j++)
		{
			boardstate[i][j] = 'N';
		}
	}
	mColours = boardstate;
	//set position and attributes of mboardarea
};

Board::Board():mboardwidth(19),mboardheight(19)
{
	char ** boardstate = new char *[mboardheight];
	for (int i = 0;i < mboardheight;i++)
	{
		boardstate[i] = new char[mboardwidth];
	}
	for (int i = 0;i < mboardheight;i++)
	{
		for (int j = 0;j < mboardwidth;j++)
		{
			boardstate[i][j] = 'N';
		}
	}
	mColours = boardstate;
};

Board::~Board()
{
	for (int i = 0;i < mboardheight;i++) delete mColours[i];
	delete mColours;
};

Board::Board(const Board& other): mboardwidth(other.mboardwidth),mboardheight(other.mboardheight)
{
	// initialise mColours
	char ** boardstate = new char *[mboardheight];
	for (int i = 0;i < mboardheight;i++)
	{
		boardstate[i] = new char[mboardwidth];
	}
	mColours = boardstate;
	for (int i = 0;i < mboardwidth;i++)
		for (int j = 0;j < mboardheight;j++)
		{
			mColours[i][j] = other.mColours[i][j];
		}
};

Board::Board(Board&& other):mboardwidth(other.mboardwidth), mboardheight(other.mboardheight)
{
	mColours = other.mColours;
	char ** boardstate = new char *[mboardheight];
	for (int i = 0;i < mboardheight;i++)
	{
		boardstate[i] = new char[mboardwidth];
	}
	other.mColours = boardstate;
};

bool Board::operator==(const Board& other) const
{
	if (&other == this) return true; // same memory location.
	bool check = mboardheight == other.mboardheight && mboardwidth == other.mboardwidth;
	if (!check) return false;
	for (int i = 0;i < mboardheight;i++)
		for (int j = 0;j < mboardwidth;j++)
			if (mColours[i][j] != other.mColours[i][j])
				return false;
	return true;
};

bool Board::operator!=(const Board& other) const
{
	return !(*this == other);
};

Board& Board::operator=(const Board& other)
{
	if (&other != this)
	{
		if (other.mboardwidth != mboardwidth || other.mboardheight != mboardheight)
		{
			throw "Board dimensions do not match";
		};
		if (other != *this)
		{
			char** colours = new char*[mboardheight];
			for (int i = 0;i < mboardheight;i++)
			{
				for (int j = 0;j < mboardwidth;j++)
				{
					colours[i][j] = other.mColours[i][j];
				}
				delete mColours[i];
			}
			delete mColours;
			mColours = colours;
		}
	}
	return *this;
};

Board& Board::operator=(Board&& other)
{
	if (&other != this)
	{
		if (other.mboardwidth != mboardwidth || other.mboardheight != mboardheight)
		{
			throw "Board dimensions do not match";
		};
		if (mColours != other.mColours)
		{
			for (int i = 0;i < mboardheight;i++)
				if (mColours[i] != other.mColours[i])
				{
					delete mColours[i];
					mColours[i] = other.mColours[i];
				}
			delete mColours;
			mColours = other.mColours;
			other.mColours = new char*[mboardheight];
			for (int i = 0;i < mboardheight;i++)
			{
				other.mColours[i] = new char[mboardwidth];
			};
		}
	}
	return *this;
};

sf::Vector2i Board::getDimensions()
{
	sf::Vector2i dimensions(mboardheight, mboardwidth);
	return dimensions;
}