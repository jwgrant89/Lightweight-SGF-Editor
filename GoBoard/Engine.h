#pragma once
#include "Board.h"
#include "Tree.h";

class Engine
{
private:
	Tree mTree;
	Node* mCurrentNode;
	Board mBoard;
	char** mBoardstate;
public:
	Engine();
	void generateBoardstate();
};