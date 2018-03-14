#pragma once
#include "stdafx.h";
#include "Coord.h";
#include "Group.h";
#include <SFML/Graphics.hpp>;
#include <set>;

#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
	const int mboardwidth = 19;
	const int mboardheight = 19;
	char** mColours;
public:
	Board(sf::Vector2i dimensions);
	Board();
	~Board();
	Board(const Board& other);
	Board(Board&& other);
	bool operator==(const Board& other) const;
	bool operator!=(const Board& other) const;
	Board& operator=(const Board& other);
	Board& operator=(Board&& other);
	char& operator[](Coord c) const;
	sf::Vector2i getDimensions() const;

	Group connectedGroup(Coord c) const;
	std::set<Group> groupBoundary(Group G) const;
	int liberties(Group G) const;
	void updateColour(Coord c, char colour);
	bool doMove(Coord c, char colour);

	void test();
};

#endif // !BOARD_H

