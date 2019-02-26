#pragma once
#include <iostream>
#include <Windows.h>
#include "rlutil.h"
class Board
{
public:
	Board();
	~Board();
	void UpdateBoard(char t, int row, int col);
	void UpdateBoard(char t, int index, bool draw);
	void DisplayBoard();
	bool GameDone()
	{
		return gameDone;
	}

	bool GameWon()
	{
		return gameWon;
	}

	bool SpotCheck(char playerInput, int row, int col);

	char CheckVictory(char ty);
	void GameFinished(char ty);

	char currentPlayer;
	void NextTurn();
	
	int BoardSize()
	{
		return boardSize;
	}

	char* GetBoard();

private:

	bool gameDone, gameWon;
	const static int boardSize = 9;
	char board[boardSize];
	int turns = 0;
};

