#include "stdafx.h"
#include "Engine.h"
#include <iostream>;

Engine::Engine(sf::Vector2i gridDimensions):mboardGridSize(gridDimensions)
{
	Board board(mboardGridSize);
	mboard = board;
	initialiseShape();
};

Engine::Engine()
{
	initialiseShape();
};

Engine::Engine(int width, int height) :mboardGridSize(sf::Vector2i(width, height))
{
	Board board(mboardGridSize);
	mboard = board;
	initialiseShape();
};

void Engine::initialiseShape()
{
	mboardShape.setSize(mboardSize);
	mboardShape.setPosition(mboardPosition);
	mboardShape.setFillColor(sf::Color::Yellow);
};

sf::Vector2f Engine::findPoint(Coord c)
{
	float xposition = mboardSize.x / (mboardGridSize.x + 4)*(c.x);
	float yposition = mboardSize.y / (mboardGridSize.y + 4)*(c.y);
	sf::Vector2f position(xposition, yposition);
	position = localCoordinates(position);
	return position;
}

std::vector<sf::RectangleShape> Engine::drawBoard()
{
	std::vector<sf::RectangleShape> contents;
	contents.push_back(mboardShape);
	for (int i = 0;i < mboardGridSize.x;i++)
	{
		sf::RectangleShape line;
		float lineposx = mboardSize.x / (mboardGridSize.x + 4)*(i+2);
		float lineposy = mboardSize.y / (mboardGridSize.y + 4)*2;
		float linelength = (mboardSize.y -1)*(mboardGridSize.y) / (mboardGridSize.y + 4)*(mboardGridSize.y - 1) / mboardGridSize.x;
		line.setPosition(sf::Vector2f(lineposx, lineposy));
		line.setFillColor(sf::Color::Black);
		line.setSize(sf::Vector2f(mlineThickness, linelength));
		contents.push_back(line);
	}
	for (int i = 0;i < mboardGridSize.y;i++)
	{
		sf::RectangleShape line;
		float lineposy = mboardSize.y / (mboardGridSize.y + 4)*(i+2);
		float lineposx = mboardSize.x / (mboardGridSize.x + 4)*2;
		float linelength = (mboardSize.x)*(mboardGridSize.x) / (mboardGridSize.x + 4)*(mboardGridSize.x-1)/mboardGridSize.x;
		line.setPosition(sf::Vector2f(lineposx, lineposy));
		line.setFillColor(sf::Color::Black);
		line.setSize(sf::Vector2f(linelength, mlineThickness));
		contents.push_back(line);
	}
	return contents;
};

void Engine::generateBoardstate(Node* node)
{
	std::vector<Node*> ancestors;
	ancestors.push_back(node);
	Node* parent = node->getParent();
	while (parent != mTree.pointerToRoot())
	{
		ancestors.push_back(parent);
		parent = parent->getParent();
	};
	for (std::vector<Node*>::reverse_iterator it = ancestors.rbegin(); it != ancestors.rend();++it)
	{
		Stone stone = ((*it)->stone());
		PlayMove(stone);		
	}
};

sf::Vector2i Engine::getGridSize()
{
	return mboardGridSize;
};

sf::Vector2f Engine::getBoardSize()
{
	return mboardSize;
};

sf::Vector2f Engine::getBoardPosition()
{
	return mboardPosition;
};

sf::Vector2f Engine::NodeSize()
{
	float sizex = mboardSize.x / (mboardGridSize.x + 4);
	float sizey = mboardSize.y / (mboardGridSize.y + 4);
	return sf::Vector2f(sizex, sizey);
};

sf::Vector2f Engine::localCoordinates(sf::Vector2f globalCoordinates)
{
	return globalCoordinates - mboardPosition;
};

sf::Vector2f Engine::localCoordinates(sf::Vector2i globalCoordinates)
{
	float localx = globalCoordinates.x - mboardPosition.x;
	float localy = globalCoordinates.y - mboardPosition.y;
	return sf::Vector2f(localx, localy);
};

void Engine::resize(sf::Vector2f newsize)
{
	mboardSize = newsize;
	mboardShape.setSize(mboardSize);
};

bool Engine::PlayMove(char colour, sf::Vector2i position)
{
	bool legalmove = mboard.doMove(Coord(position), colour);
	if (!legalmove) return false;
	Node* currentMove = mTree.currentMove();
	Stone newstone(colour, position);
	Node* nextMove = mTree.add(newstone, currentMove);
	mTree.select(nextMove);
	return true;
};

bool Engine::PlayMove(char colour, Coord coord)
{
	bool legalmove = mboard.doMove(coord, colour);
	if (!legalmove) return false;
	Stone newstone(colour, coord);
	Node* currentMove = mTree.currentMove();
	Node* nextMove = mTree.add(newstone, currentMove);
	mTree.select(nextMove);
	return true;
}

bool Engine::PlayMove(Stone stone)
{
	Coord coord = stone.coord();
	char colour = stone.colour();
	return PlayMove(colour, coord);
}

char Engine::turnColour() const
{
	if (mTree.currentMove()->colour()=='N') return 'B'; // case of root node
	char currentColour = mTree.currentMove()->colour();
	char nextColour;
	currentColour == 'B' ? nextColour = 'W':nextColour = 'B';
	return nextColour;
}

std::vector<sf::CircleShape> Engine::stoneShapes()
{
	std::vector<sf::CircleShape> stones;
	sf::Vector2f nodesize = NodeSize();
	sf::Vector2i gridsize = getGridSize();
	for (int i = 0;i<gridsize.x;i++)
		for (int j = 0;j < gridsize.y;j++)
		{
			Coord c(i, j);
			if (mboard[c] == 'B')
			{
				sf::CircleShape stone;
				sf::Vector2f position = findPoint(c);
				position.x = position.x - nodesize.x / 2;
				position.y = position.y - nodesize.y / 2;
				stone.setPosition(position);
				stone.setFillColor(sf::Color::Black);
				stone.setRadius(nodesize.x/2);
				stones.push_back(stone);
			}
			if (mboard[c] == 'W')
			{
				sf::CircleShape stone;
				sf::Vector2f position = findPoint(c);
				position.x = position.x - nodesize.x / 2;
				position.y = position.y - nodesize.y / 2;
				stone.setPosition(position);
				stone.setFillColor(sf::Color::White);
				stone.setRadius(nodesize.x/2);
				stones.push_back(stone);
			}
		}
	return stones;
}