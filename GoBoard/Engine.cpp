#include "stdafx.h"
#include "Engine.h"
#include <iostream>;

Engine::Engine(sf::Vector2i gridDimensions):mboardGridSize(gridDimensions)
{
	mCurrentNode = mTree.pointerToRoot();
	Board board(mboardGridSize);
	mboard = board;
	initialiseShape();
};

Engine::Engine()
{
	mCurrentNode = mTree.pointerToRoot();
	initialiseShape();

};

Engine::Engine(int width, int height) :mboardGridSize(sf::Vector2i(width, height))
{
	mCurrentNode = mTree.pointerToRoot();
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

std::vector<sf::RectangleShape> Engine::drawBoard()
{
	std::vector<sf::RectangleShape> contents;
	contents.push_back(mboardShape);
	for (int i = 0;i <= mboardGridSize.x;i++)
	{
		sf::RectangleShape line;
		float lineposx = mboardSize.x / (mboardGridSize.x + 4)*(i+2);
		float lineposy = mboardSize.y / (mboardGridSize.y + 4)*2;
		float linelength = mboardSize.y*(mboardGridSize.y) / (mboardGridSize.y + 4);
		line.setPosition(sf::Vector2f(lineposx, lineposy));
		line.setFillColor(sf::Color::Black);
		line.setSize(sf::Vector2f(mlineThickness, linelength));
		contents.push_back(line);
	}
	for (int i = 0;i <= mboardGridSize.y;i++)
	{
		sf::RectangleShape line;
		float lineposy = mboardSize.y / (mboardGridSize.y + 4)*(i+2);
		float lineposx = mboardSize.x / (mboardGridSize.x + 4)*2;
		float linelength = mboardSize.x*(mboardGridSize.x) / (mboardGridSize.x + 4);
		line.setPosition(sf::Vector2f(lineposx, lineposy));
		line.setFillColor(sf::Color::Black);
		line.setSize(sf::Vector2f(linelength, mlineThickness));
		contents.push_back(line);
	}
	return contents;
};

void Engine::generateBoardstate()
{

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
	Stone newstone(colour, position);
	Node nextMove(newstone,mCurrentNode);
	return true;
};