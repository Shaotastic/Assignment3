#include "AI.h"



AI::AI()
{}
AI::~AI()
{}

AI::AIMove AI::GetMoves(Board &board, char &player, int maxDepth)
{
	Board tempBoard = board;
	if (tempBoard.CheckVictory(aiLetter) == aiLetter || maxDepth == 0)
		return AIMove( 10);
	else if (tempBoard.CheckVictory(playerLetter) == playerLetter || maxDepth == 0)
		return AIMove( -10);
	else if (tempBoard.CheckVictory(player) == 'D' || maxDepth == 0)
		return AIMove(0);

	std::vector<AIMove> moves;

	for (int i = 0; i < tempBoard.BoardSize(); i++)
	{
		if (tempBoard.GetBoard()[i] == NULL)
		{
			AIMove move;
			move.index = i;
			tempBoard.UpdateBoard(player, i, false); 
			if (player == aiLetter)
				move.score = GetMoves(tempBoard, playerLetter, maxDepth - 1).score;
			else if (player == playerLetter)
				move.score = GetMoves(tempBoard, aiLetter, maxDepth - 1).score;

			moves.push_back(move);
			tempBoard.UpdateBoard(NULL, i, false);
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
				tempBoard.UpdateBoard(player, i, false);
				move.index = i;
				move.score = 0;
				move = GetMoves(tempBoard, playerLetter, maxDepth - 1, alpha, beta, i);
				maxVal = max(maxVal, move.score);
				alpha = max(alpha, maxVal);
				if (alpha >= beta)
					break;
			}
		}
		return move;
	}
	else if (player == playerLetter)
	{
		for (int i = 0; i < tempBoard.BoardSize(); i++)
		{
			int minVal = 100;
			if (tempBoard.GetBoard()[i] == NULL)
			{
				tempBoard.UpdateBoard(player, i, false);
				move.index = i;
				move.score = 0;
				move = GetMoves(tempBoard, aiLetter, maxDepth - 1, alpha, beta, i);
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
		if (algorithm == 1)
		{
			AIMove newMove = GetMoves(board, aiLetter, maxDepth);
			board.UpdateBoard(aiLetter, newMove.index, true);
			board.NextTurn();
		}
		else if (algorithm == 2)
		{
			AIMove newMove = GetMoves(board, aiLetter, maxDepth, -INFINITY, INFINITY, 0);
			board.UpdateBoard(aiLetter, newMove.index, true);
			board.NextTurn();
		}
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
