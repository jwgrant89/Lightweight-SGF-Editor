#include "stdafx.h"
#include "Node.h";

Node::Node(Stone &stone)
{
	mstone = &stone;
};

Node::Node(Stone &stone, Node* parent)
{
	mstone = &stone;
	mparent = parent;
}

Node::Node()
{
	mstone = new Stone();
};

Node* Node::getParent()
{
	return mparent;
}

void Node::addChild(Node* childnode)
{
	mchildren.push_back(childnode);
	childnode->mparent = this;
};

Node* Node::getChild(int n)
{
	return mchildren[n];
};

Stone* Node::getStone()
{
	return mstone;
}

char Node::getColour()
{
	return this->getStone()->getColour();
}