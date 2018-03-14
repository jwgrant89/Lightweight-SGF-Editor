#include "stdafx.h";
#include "Group.h";

Group::Group()
{};

Group::Group(std::set<Coord> coords)
{
	mCoords = coords;
}

Group::Group(std::set<Coord> coords, char colour)
{
	mCoords = coords;
	mColour = colour;
}

Group::Group(char colour)
{
	mColour = colour;
}

bool Group::contains(Coord c) const
{
	return (bool)mCoords.count(c);
}

std::set<Coord> Group::coords() const
{
	return mCoords;
}

void Group::insert(Coord c)
{
	mCoords.insert(c);
}

int Group::count(Coord c) const
{
	return mCoords.count(c);
}

char Group::colour() const
{
	return mColour;
}

bool Group::operator<(const Group& other) const
{
	//compare on the smallest coordinate in each group;
	Coord min1(sf::Vector2i(255,255));
	for (auto it = mCoords.begin(); it != mCoords.end();++it)
	{
		if ((*it) < min1) min1 = *it;
	}
	Coord min2(sf::Vector2i(255, 255));
	for (auto it = other.mCoords.begin();it != other.mCoords.end();++it)
	{
		if ((*it) < min2) min2 = *it;
	}
	return min1 < min2;
};

int Group::size() const
{
	return mCoords.size();
}