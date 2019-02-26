// Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip> 
#include <string>
#include <Windows.h>
#include "Board.h"
#include "AI.h"

void PlayerTurn();
void IntializeAI();
bool gameStart = false;
char player;
std::string input;
Board board = Board();
AI ai = AI();

int main()
{
	std::cout << "==========Tic Tac Toe==========" << std::endl;
	std::cout << "\n\nWelcome to Tic Tac Toe, X's or O's?" << std::endl << std::endl;

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

	IntializeAI();

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

			if (player == 'X')
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

void IntializeAI()
{
	std::cout << "\nSelect bot difficulty:\nMiniMax = 1, AB = 2" << std::endl;
	int al = 0;
	int diff = 0;
	while (true)
	{
		std::cin >> al;
		if (al != 1 && al != 2)
			std::cout << "Input invalid, please select the appropriate option." << std::endl;
		else if (al == 1)
		{
			ai.SetAlgorithm(2);
			break;
		}
		else if (al == 2)
		{
			ai.SetAlgorithm(2);
			break;
		}
	}

	std::cout << "\nSelect bot depth search length from 1-10." << std::endl;

	while (true)
	{
		std::cin >> diff;

		if (diff >= 1 && diff <= 10)
		{
			ai.SetDifficulty(diff);
			break;
		}
		else
			std::cout << "Input invalid, please select the appropriate depth length." << std::endl;

	}
}
