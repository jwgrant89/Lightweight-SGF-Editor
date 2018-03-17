#include "stdafx.h"
#include "Tree.h";

Tree::Tree(Node newroot)
{
	mallNodes.push_back(newroot);
	mroot = &(mallNodes[0]);
	mcurrent = mroot;
}

Tree::Tree(Stone stone)
{
	Node root(stone);
	mallNodes.push_back(root);
	mroot = &(mallNodes[0]);
	mcurrent = mroot;
}
Tree::Tree()
{
	Node root;
	mallNodes.push_back(root);
	mroot = &(mallNodes[0]);
	mcurrent = mroot;
};

Node* Tree::pointerToRoot()
{
	return mroot;
}

Node* Tree::add(Node& newnode, Node* toNode)
{
	//add the node and return a reference to it in the allNodes vector;
	toNode->addChild(&newnode);
	mallNodes.push_back(newnode);
	int numberofNodes = mallNodes.size();
	return &(mallNodes[numberofNodes - 1]);
}

Node* Tree::add(Stone& stone, Node* toNode)
{
	Node newnode(stone, toNode);
	mallNodes.push_back(newnode);
	int numberofNodes = mallNodes.size();
	return &(mallNodes[numberofNodes - 1]);
}

void Tree::select(Node* newcurrent)
{
	mcurrent = newcurrent;
};

Node* Tree::currentMove() const
{
	return mcurrent;
};