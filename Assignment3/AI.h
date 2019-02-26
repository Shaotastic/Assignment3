#pragma once
#include "Board.h"
#include <vector>
#include <math.h>
#include <algorithm>


class AI
{
	struct AIMove
	{
		AIMove()
		{}
		AIMove(int Score) : score(Score)
		{}
		AIMove(int Index, int Score) : index(Index), score(Score)
		{}

		int index;
		int score;
	};

public:
	AI();
	~AI();

	AIMove GetMoves(Board &board, char &player, int maxDepth); //Uses the Minimax Algorithm
	AIMove GetMoves(Board &board, char &player, int maxDepth, int alpha, int beta, int index); //Uses AB Pruning

	void MakeMove(Board &board);
	void SetAI(char value);
	void SetDifficulty(int value)
	{
		maxDepth = value;
	}

	void SetAlgorithm(int x)
	{
		algorithm = x;
	}

	char GetLetter()
	{
		return aiLetter;
	}



private:
	char aiLetter, playerLetter;
	int maxDepth = 0;
	int algorithm = 0;
};

