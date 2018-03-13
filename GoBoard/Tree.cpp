#include "stdafx.h"
#include "Tree.h";

Tree::Tree(Node newroot)
{
	mroot = newroot;
}

Tree::Tree()
{
}

Node* Tree::pointerToRoot()
{
	return &mroot;
}