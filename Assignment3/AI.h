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
		{
		}
		AIMove(int Score) : score(Score)
		{
		}
		int index;
		int score;
	};

public:
	AI();
	~AI();

	AIMove GetMoves(Board &board, char &player);
	AIMove GetMoves(Board &board, char &player, int maxDepth, int currentDepth, int alpha, int beta);

	int Max(int a, int b)
	{
		return ((a) > (b)) ? (a) : (b);
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

