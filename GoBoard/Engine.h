#pragma once
#include "Board.h";
#include "Tree.h";
#include <SFML/Graphics.hpp>;

class Engine
{
private:
	Tree mTree;
	sf::RectangleShape mboardShape;
	sf::Vector2f mboardSize = sf::Vector2f(500, 500);
	sf::Vector2f mboardPosition = sf::Vector2f(0, 0);
	const sf::Vector2i mboardGridSize = sf::Vector2i(19,19);
	Board mboard;
	float mlineThickness = 2;
 
public:
	Engine(sf::Vector2i boardgridsize);
	Engine(int width, int height);
	Engine();
	void initialiseShape();
	void generateBoardstate(Node* node);
	bool PlayMove(char colour, sf::Vector2i position);
	bool PlayMove(char colour, Coord coord);
	bool PlayMove(Stone stone);
	sf::Vector2i getGridSize();
	sf::Vector2f getBoardSize();
	sf::Vector2f getBoardPosition();
	sf::Vector2f findPoint(Coord c);
	sf::Vector2f localCoordinates(sf::Vector2f globalCoordinates);
	sf::Vector2f localCoordinates(sf::Vector2i globalCoordinates);
	sf::Vector2f NodeSize();
	void resize(sf::Vector2f);
	std::vector<sf::RectangleShape> drawBoard();
	char turnColour() const;
	std::vector<sf::CircleShape> stoneShapes();
};