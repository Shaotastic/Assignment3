#pragma once
#include <iostream>

class Board
{
public:
	Board();
	~Board();
	void UpdateBoard(char t, int row, int col);
	void UpdateBoard(char t, int index);
	void DisplayBoard();
	bool GameDone()
	{
		return gameDone;
	}

	bool GameWon()
	{
		return gameWon;
	}

	char CheckVictory(char ty);
	char PotentialVictory(char ty);

	char currentPlayer;
	void NextTurn();
	
	int BoardSize()
	{
		return boardSize;
	}

	char* GetBoard();

private:

	void BoardFull();

	bool gameDone, gameWon;
	const static int boardSize = 9;
	char board[boardSize];
	int turns = 0;

	//char board[numRow][numCol] = {0};
};

