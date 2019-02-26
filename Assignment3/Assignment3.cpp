// Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip> 
#include <string>
#include <Windows.h>
#include "Board.h"
#include "AI.h"
#include "rlutil.h"

void PlayerTurn();
bool gameStart = false;
char player;
std::string input;
Board board = Board();
AI ai = AI();

int main()
{
	std::cout << "==========Tic Tac Toe==========" << std::endl;
	std::cout << "\n\nWelcome to Tic Tac Toe, X's or O's?" << std::endl << std::endl;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (true)
	{
		std::cin >> std::setw(1) >> player;
		if (player != 'X' && player != 'O')
			std::cout << "Input invalid, please select X's or O's" << std::endl;

		else
		{
			if (player == 'X')
				ai.SetAI('O');
			else
				ai.SetAI('X');

			gameStart = true;
			break;
		}
	}

	std::cout << "\nPlayer is: " << player << " | Bot is: " << ai.GetLetter() << std::endl << std::endl;

	board.DisplayBoard();

	if (player == 'X')
		board.currentPlayer = player;
	else
		board.currentPlayer = ai.GetLetter();


	while (!board.GameDone())
	{
		if (board.currentPlayer == player)
		{
			Beep(500, 500);

			if(player == 'X')
				rlutil::setColor(10);
			else
				rlutil::setColor(5);

			PlayerTurn();
		}

		else if (board.currentPlayer == ai.GetLetter())
		{
			ai.MakeMove(board);
			board.GameFinished(ai.GetLetter());
			Beep(200, 500);
		}
	}


	system("pause");
	return 0;
}

void PlayerTurn()
{
	int first, second;
	std::cout << "Enter the row number: ";
	std::cin >> first;
	std::cout << "Enter the column number: ";
	std::cin >> second;

	if (board.SpotCheck(player, first, second))
	{
		board.UpdateBoard(player, first, second);
		board.GameFinished(player);
		board.NextTurn();
	}
}
