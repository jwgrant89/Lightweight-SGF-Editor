#pragma once
#include "Node.h";

#ifndef TREE_H
#define TREE_H

class Tree
{
private:
	Node mroot;
	Node* current;
public:
	Tree(Node newroot);
	Tree(Stone stone);
	Tree();
	Node* pointerToRoot();
	void add(Node newnode, Node oldnode);
};


#endif // !TREE_H
