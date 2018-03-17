#pragma once
#include "Node.h";

#ifndef TREE_H
#define TREE_H

class Tree
{
private:
	Node* mroot;
	Node* mcurrent;
	std::vector<Node> mallNodes;
public:
	Tree(Node newroot);
	Tree(Stone stone);
	Tree();
	Node* pointerToRoot();
	Node* currentMove() const;
	void select(Node* newcurrent);
	Node* add(Node& newnode, Node* toNode);
	Node* add(Stone& stone, Node* toNode);
};


#endif // !TREE_H
