#pragma once
#include "Node.h";

#ifndef TREE_H
#define TREE_H

class Tree
{
private:
	Node mroot;
public:
	Tree(Node newroot);
	Tree();
	Node* pointerToRoot();
};


#endif // !TREE_H
