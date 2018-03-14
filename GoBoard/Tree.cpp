#include "stdafx.h"
#include "Tree.h";

Tree::Tree(Node newroot):mroot(newroot)
{
}

Tree::Tree(Stone stone):mroot(Node(stone))
{
}
Tree::Tree() : mroot(Node(Stone()))
{
};

Node* Tree::pointerToRoot()
{
	return &mroot;
}