#pragma once
#include "Stone.h"
#include <vector>;

#ifndef NODE_H
#define NODE_H
class Node
{
private:
	Stone* mstone;
	Node* mparent;
	std::vector<Node*> mchildren;
public:
	Node(Stone &stone);
	Node();
	~Node();
	Stone* getStone();
	Node* getParent();
	void addChild(Node* childnode);
	Node* getChild(int n);
	char getColour();
};


#endif // !NODE_H

