#include "AI.h"



AI::AI()
{
}


AI::~AI()
{
}
AI::AIMove AI::GetMoves(Board &board, char &player)
{
	if (board.CheckVictory(aiLetter) == aiLetter)
		return AIMove(10);
	else if (board.CheckVictory(playerLetter) == playerLetter)
		return AIMove(-10);
	else if (board.CheckVictory(player) == 'D')
		return AIMove(0);

	std::vector<AIMove> moves;

	for (int i = 0; i < board.BoardSize(); i++)
	{

		if (board.GetBoard()[i] == NULL)
		{
			AIMove move;
			move.index = i;
			board.UpdateBoard(player, i);

			if (player == aiLetter)
				move.score = GetMoves(board, playerLetter).score;
			else if (player == playerLetter)
				move.score = GetMoves(board, aiLetter).score;
			moves.push_back(move);
			board.UpdateBoard(NULL, i);
		}
	}
	int bestMove = 0;

	if (player == aiLetter)
	{
		int bestScore = -100;
		for (int i = 0; i < moves.size(); i++)
		{
			if (moves[i].score > bestScore)
			{
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	}
	else
	{
		int bestScore = 100;
		for (int i = 0; i < moves.size(); i++)
		{
			if (moves[i].score < bestScore)
			{
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	}


	return moves[bestMove];
}

AI::AIMove AI::GetMoves(Board & board, char & player, int maxDepth, int currentDpeth, int alpha, int beta)
{
	if (board.CheckVictory(aiLetter) == aiLetter)
		return AIMove(10);
	else if (board.CheckVictory(playerLetter) == playerLetter)
		return AIMove(-10);
	else if (board.CheckVictory(player) == 'D')
		return AIMove(0);

	std::vector<AIMove> moves;

	int bestScore = 100;

	for (int i = 0; i < board.BoardSize(); i++)
	{

		if (board.GetBoard()[i] == NULL)
		{
			AIMove move;
			move.index = i;
			board.UpdateBoard(player, i);

			if (player == aiLetter)
				move.score = GetMoves(board, playerLetter, 10, currentDpeth+1, -alpha, Max(alpha, bestScore)).score;
			else if (player == playerLetter)
				move.score = GetMoves(board, aiLetter).score;
			moves.push_back(move);
			board.UpdateBoard(NULL, i);
		}
	}

	return AIMove();
}

void AI::MakeMove(Board &board)
{
	if (!board.GameDone())
	{
		AIMove newMove = GetMoves(board, aiLetter);

		board.UpdateBoard(aiLetter, newMove.index);
		board.NextTurn();
	}
}

void AI::SetAI(char value)
{
	aiLetter = value;

	if (aiLetter == 'X')
		playerLetter = 'O';
	else if (aiLetter == 'O')
		playerLetter = 'X';
}

int AI::Score(Board board)
{
	if (board.CheckVictory(aiLetter))
		return 1;
	else if (board.CheckVictory(!aiLetter))
		return -1;
	else
		return 0;
}
