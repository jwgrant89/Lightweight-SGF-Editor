#include "stdafx.h"
#include "Node.h";

Node::Node(Stone stone)
{
	mstone = stone;
};

Node::Node(Stone stone, Node* parent)
{
	mstone = stone;
	mparent = parent;
	parent->addChild(this);
}

Node::Node()
{
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

Stone Node::stone() const
{
	return mstone;
}

char Node::colour() const
{
	return this->stone().colour();
}