#pragma once
#include "stdafx.h"
#include "Coord.h"
#include <set>;

#ifndef GROUP_H
#define GROUP_H

class Group
{
private:
	std::set<Coord> mCoords;
	char mColour;
public:
	Group(std::set<Coord> coords);
	Group(std::set<Coord> coords, char colour);
	Group(char colour);
	Group();
	bool operator<(const Group& other) const;
	std::set<Coord> coords() const;
	bool contains(Coord c) const;
	void insert(Coord c);
	int count(Coord c) const;
	char colour() const;
	int size() const;
};
#endif // !GROUP_H
