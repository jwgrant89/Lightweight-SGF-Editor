// GoBoard.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include "Board.h"
#include "Engine.h"
#include "GameEngine.h";
#include <iostream>;

int main()
{
	Stone stone1;
	Stone stone2;
	Node node1(stone1);
	Node node2(stone2);
	node1.addChild(&node2);
	std::cout << node1.getChild(0)->colour();
	stone2.setColour('W');
	std::cout << stone2.colour();
	std::cout << node1.getChild(0)->colour();
	std::cout << node2.getParent()->stone().colour();
	stone1.setColour('B');
	std::cout << node2.getParent()->stone().colour() << std::endl;
	//std::cout << node1.firstChild().getStone().getColour();
	//node1.firstChild().getStone().setColour('W');
	//std::cout << node1.firstChild().getStone().getColour();
	Board board(sf::Vector2i(9, 9));
	board.test();
	std::cout << board.getDimensions().x;
	GameEngine gameengine;
	gameengine.start();
    return 0;
}

