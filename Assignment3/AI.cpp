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

AI::AIMove AI::GetMoves(Board & board, char & player, int maxDepth, int alpha, int beta, int index)
 {
	Board tempBoard = board;

	if (tempBoard.CheckVictory(aiLetter) == aiLetter || maxDepth == 0)
		return AIMove(index, 10);
	else if (tempBoard.CheckVictory(playerLetter) == playerLetter || maxDepth == 0)
		return AIMove(index, -10);
	else if (tempBoard.CheckVictory(player) == 'D' || maxDepth == 0)
		return AIMove(index, 0);

	AIMove move;

	if (player == aiLetter)
	{
		for (int i = 0; i < tempBoard.BoardSize(); i++)
		{
			int maxVal = -100;
			if (tempBoard.GetBoard()[i] == NULL)
			{
				tempBoard.UpdateBoard(player, i);
				move.index = i;
				move.score = 0;
				move = GetMoves(tempBoard, playerLetter, maxDepth - 1, alpha, beta, i);
				//move.index = i;
				maxVal = max(maxVal, move.score);
				alpha = max(alpha, maxVal);
				if (alpha >= beta)
					break;
			}
		}
		return move;
	}
	else if(player == playerLetter)
	{
		for (int i = 0; i < tempBoard.BoardSize(); i++)
		{
			int minVal = 100;
			if (tempBoard.GetBoard()[i] == NULL)
			{
				tempBoard.UpdateBoard(player, i);
				move.index = i;
				move.score = 0;
				move = GetMoves(tempBoard, aiLetter, maxDepth - 1, alpha, beta, i);
				//move.index = i;
				minVal = min(minVal, move.score);
				beta = min(beta, minVal);
				if (alpha >= beta)
					break;
			}
		}
		return move;
	}
}

void AI::MakeMove(Board &board)
{
	if (!board.GameDone())
	{
		//AIMove newMove = GetMoves(board, aiLetter);
		AIMove newMove = GetMoves(board, aiLetter, 2, -INFINITY, INFINITY, 0);

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
