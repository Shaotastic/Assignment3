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

	AIMove GetMoves(Board &board, char &player);
	AIMove GetMoves(Board &board, char &player, int maxDepth, int alpha, int beta, int index);

	int Max(int a, int b)
	{
		return ((a) > (b)) ? (a) : (b);
	}

	int Min(int a, int b)
	{
		return ((a) < (b)) ? (b) : (a);
	}

	void MakeMove(Board &board);

	void SetAI(char value);

	char GetLetter()
	{
		return aiLetter;
	}

	int Score(Board board);

private:
	char aiLetter, playerLetter;
	int currentScore, bestScore;
};

