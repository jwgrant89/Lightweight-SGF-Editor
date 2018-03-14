#pragma once
#include "Engine.h";
#include <SFML/Graphics.hpp>;

#ifndef GAMEENGINE_H
#define GAMEENGINE_H
class GameEngine
{
private:
	Engine mengine;
	sf::RenderWindow mwindow;
	sf::RectangleShape mCursor;
	sf::Vector2i resolution = sf::Vector2i(1000, 1000);

public:
	GameEngine();
	GameEngine(int width, int height);

	sf::Vector2i nodeMousePosition(sf::Vector2f(position));
	sf::Vector2i nodeMousePosition();
	void setCursorPosition(sf::Vector2f(position));

	void start();
	void update();
	void resize();
	void input();
	void draw();
};

#endif // !GAMEENGINE_H

