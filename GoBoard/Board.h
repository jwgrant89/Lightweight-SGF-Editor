#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>;

#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
	sf::RectangleShape mboardarea;
	const int mboardwidth;
	const int mboardheight;

public:
	Board(int boardwidth, int boardheight);
	Board();
	~Board();
	Board(const Board& other);
	Board(Board&& other);
	void initaliseBoardArea();
	bool operator==(const Board& other) const;
	bool operator!=(const Board& other) const;
	Board& operator=(const Board& other);
	Board& operator=(Board&& other);

	sf::Vector2i getDimensions();
	void draw();
};

#endif // !BOARD_H

