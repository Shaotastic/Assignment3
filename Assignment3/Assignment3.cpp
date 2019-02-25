// Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip> 
#include <string>
#include "Board.h"
#include "AI.h"

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

	std::cout << "Player is: " << player << " | Bot is: " << ai.GetLetter() << std::endl;

	board.DisplayBoard();

	if (player == 'X')
		board.currentPlayer = player;
	else
		board.currentPlayer = ai.GetLetter();


	while (!board.GameDone())
	{
		if (board.currentPlayer == player)
		{
			PlayerTurn();
			board.NextTurn();
		}

		else if (board.currentPlayer == ai.GetLetter())
		{
			ai.MakeMove(board);
			system("cls");
			board.DisplayBoard();
		
		}
	}

	if (board.GameWon())
	{
		std::cout << "\nWinner is " << board.currentPlayer << std::endl;
	}
	else
		std::cout << "Game ended in a draw" << std::endl;


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

	board.UpdateBoard(player, first, second);
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
