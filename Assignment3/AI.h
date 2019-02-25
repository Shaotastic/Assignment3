#pragma once
#include "Board.h"
#include <vector>
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
	std::vector<Board> moves;
	std::vector<char*> boards;
	std::vector<int> scores;
};

