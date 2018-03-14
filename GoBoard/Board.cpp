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

sf::Vector2i Board::getDimensions() const
{
	sf::Vector2i dimensions(mboardheight, mboardwidth);
	return dimensions;
};

char& Board::operator[](Coord c) const
{
	return mColours[c.y][c.x];
};

Group Board::connectedGroup(Coord c) const
{
	Board self = *this;
	char colour = self[c];
	Group result(colour);
	std::set<Coord> next;
	result.insert(c);
	if (colour == 'N') return result; //singleton
	std::vector<Coord> liberties = c.liberties();
	for (std::vector<Coord>::iterator it = liberties.begin(); it != liberties.end(); ++it) {
		if (self[*it] == colour)
		{
			next.insert(*it);
		}
	};
	while (!next.empty())
	{
		std::set<Coord> next2;
		for (std::set<Coord>::iterator it = next.begin(); it != next.end(); ++it)
		{
			result.insert(*it);
			std::vector<Coord> nextliberties = it->liberties();
			for (std::vector<Coord>::iterator libit = nextliberties.begin(); libit != nextliberties.end(); ++libit)
			{
				if (self[*libit] == colour && !(bool)result.count(*libit) && !(bool)next.count(*libit))
				{
					next2.insert(*libit);
				};
			};
		};
		next = next2;
	}
	return result;
};

std::set<Group> Board::groupBoundary(Group G) const
{
	std::set<Group> boundary;
	std::set<Coord> coords = G.coords();
	for (auto it = coords.begin();it != coords.end();++it)
	{
		std::vector<Coord> liberties = it->liberties();
		for (auto libit = liberties.begin(); libit != liberties.end();++libit)
		{
			boundary.insert(connectedGroup(*libit));
		}
	}
	return boundary;
};

int Board::liberties(Group G) const
{
	int sum = 0;
	std::set<Group> boundary = groupBoundary(G);
	for (auto it = boundary.begin(); it != boundary.end();++it)
	{
		if (it->colour() == 'N' || it->colour() == 'K') sum++;
	}
	return sum;
};

void Board::updateColour(Coord c, char colour)
{
	(*this)[c] = colour;
}

bool Board::doMove(Coord c, char colour)
{
	if ((*this)[c] != 'N') return false;
	Board oldboard(*this);
	updateColour(c, colour);
	//reset old ko, since we already return false if tried to play on a ko
	for (int i = 0;i < mboardheight;i++)
		for (int j = 0;j < mboardwidth;j++)
			if (mColours[i][j] == 'K') mColours[i][j] = 'N';
	Group group = connectedGroup(c);
	std::set<Group> boundary = groupBoundary(group);
	for (auto it = boundary.begin(); it != boundary.end();++it)
	{
		if (liberties(*it) == 0)
		{
			//group is captured (maybe it is already "N")
			if (group.size() == 1 && liberties(group) == 0 && it->size() == 1 && it->colour()!='N' && it->colour()!='K')
			{
				//ko situation
				updateColour(*((*it).coords().begin()), 'K');
			}
			else
			{
				std::set<Coord> coords = it->coords();
				for (auto each = coords.begin(); each != coords.end();++each)
				{
					updateColour(*each, 'N');
				};
			};
		};
	};
	//at this point the move we just placed should have some liberties if it was a legal move
	if (liberties(group) > 0)
	{
		return true;
	}
	else
	{
		*this = oldboard;
		return false;
	}
};

void Board::test()
{
	Coord coord1(3, 4);
	Coord coord2(4, 4);
	Coord coord3(4, 3);
	Coord coord4(3,3);
	Coord coord5(5, 4);
	updateColour(coord1, 'W');
	updateColour(coord2, 'W');
	updateColour(coord3, 'W');
	updateColour(coord4, 'W');
	std::cout << liberties(connectedGroup(coord1));
	std::cout << liberties(connectedGroup(coord5));
}