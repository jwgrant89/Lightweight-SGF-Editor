#pragma once
#include "Stone.h"
#include <vector>;

#ifndef NODE_H
#define NODE_H
class Node
{
private:
	Stone mstone;
	Node* mparent;
	std::vector<Node*> mchildren;
public:
	Node(Stone stone);
	Node(Stone stone, Node* parent);
	Node();
	Stone stone() const;
	Node* getParent();
	void addChild(Node* childnode);
	Node* getChild(int n);
	char colour() const;
};


#endif // !NODE_H

