#pragma once
#include "stdafx.h";
#include <SFML/Graphics.hpp>;

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
	sf::Vector2i getDimensions();
};

#endif // !BOARD_H

