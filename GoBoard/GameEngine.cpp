#include "stdafx.h"
#include "GameEngine.h";
#include <iostream>;

GameEngine::GameEngine(int width, int height):mengine(Engine(width,height))
{
	mwindow.create(sf::VideoMode(resolution.x,resolution.y), "Go Board", sf::Style::Close);
	mCursor.setSize(mengine.NodeSize());
	mCursor.setFillColor(sf::Color::Black);
};

GameEngine::GameEngine()
{
	mwindow.create(sf::VideoMode(resolution.x, resolution.y), "Go Board", sf::Style::Close | sf::Style::Resize);
	mCursor.setSize(mengine.NodeSize());
	mCursor.setFillColor(sf::Color::Black);
};

void GameEngine::start()
{
	while (mwindow.isOpen())
	{
		sf::Event event;
		while (mwindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mwindow.close();
		}
		input();
		update();
		draw();
	}
};

void GameEngine::input()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePos = nodeMousePosition();
		char colourToPlay = mengine.turnColour();
		mengine.PlayMove(colourToPlay,mousePos);
		if (mengine.turnColour() == 'B')
			mCursor.setFillColor(sf::Color::Black);
		else
			mCursor.setFillColor(sf::Color::White);
	}
}

void GameEngine::setCursorPosition(sf::Vector2f(position))
{
	sf::Vector2f nodesize = mengine.NodeSize();
	sf::Vector2i nodeposition = nodeMousePosition(position);
	sf::Vector2f rectanglePosition(nodesize.x*(nodeposition.x +2 - 0.5), nodesize.y*(nodeposition.y+2 - 0.5));
	mCursor.setPosition(rectanglePosition);
};

sf::Vector2i GameEngine::nodeMousePosition(sf::Vector2f(position))
{
	sf::Vector2f nodesize = mengine.NodeSize();
	float snaptox = -0.5;
	int maxx = nodesize.x*(mengine.getGridSize().x);
	while ((snaptox+2)*nodesize.x < position.x-nodesize.x && (snaptox+2)*nodesize.x < maxx) snaptox++;
	float snaptoy = -0.5;
	int maxy = nodesize.y*(mengine.getGridSize().y);
	while ((snaptoy+2)*nodesize.y < position.y-nodesize.y && (snaptoy+2)*nodesize.y < maxy) snaptoy++;
	int nodex = int(snaptox + 1);
	int nodey = int(snaptoy + 1);
	return sf::Vector2i(nodex, nodey);
}

sf::Vector2i GameEngine::nodeMousePosition()
{
	sf::Vector2f position = mengine.localCoordinates(sf::Mouse::getPosition(mwindow));
	return nodeMousePosition(position);
}

void GameEngine::draw()
{
	mwindow.clear(sf::Color::Black);
	//draw the game board
	std::vector<sf::RectangleShape> shapes = mengine.drawBoard();
	for (std::vector<sf::RectangleShape>::iterator it = shapes.begin(); it != shapes.end();++it)
	{
		mwindow.draw(*it);
	}
	std::vector<sf::CircleShape> stones = mengine.stoneShapes();
	for (auto it = stones.begin();it != stones.end(); ++it)
	{
		mwindow.draw(*it);
	}
	//draw the cursor
	mwindow.draw(mCursor);
	mwindow.display();
}

void GameEngine::update()
{
	sf::Vector2f position = mengine.localCoordinates(sf::Mouse::getPosition(mwindow));
	setCursorPosition(position);
	
}

