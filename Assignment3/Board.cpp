#include "Board.h"


Board::Board()
{
	rlutil::saveDefaultColor();
}


Board::~Board()
{}

void Board::UpdateBoard(char playerInput, int row, int col)
{
	//std::cout << "\a";


	if (playerInput == 'X' || playerInput == 'O' && !gameDone)
	{
		if (row >= 1 && row <= 3)
		{
			int index;
			if (row == 1)
			{
				index = (row + col) - 2;
				if (board[index] == NULL)
					board[index] = playerInput;
				else
				{

				}
			}
			else if (row == 2)
			{
				index = row + col;
				if (board[index] == NULL)
					board[index] = playerInput;
				else
				{

				}
			}
			else if (row == 3)
			{
				index = (row + col) + 2;
				if (board[index] == NULL)
					board[index] = playerInput;
				else
				{}
			}

			CheckVictory(playerInput);
			system("cls");
			DisplayBoard();
			//NextTurn();
		}
	}
}

void Board::UpdateBoard(char t, int index)
{
	//BoardFull();

	if (t == 'X' || t == 'O' || t == NULL && !gameDone)
	{
		if (index >= 0 && index < boardSize)
		{
			if (board[index] == NULL)
			{
				board[index] = t;
			}
			else if (board[index] != NULL && t == NULL)
			{
				board[index] = NULL;
			}
			CheckVictory(t);
			system("cls");
			DisplayBoard();
			//NextTurn();
		}
	}

}

void Board::DisplayBoard()
{
	rlutil::resetColor();
	std::cout << "    1   2   3" << std::endl;
	std::cout << "  -------------" << std::endl;
	std::cout << "1 | ";

	if (board[0] == 'X')
		rlutil::setColor(10);
	else if (board[0] == 'O')
		rlutil::setColor(5);

	std::cout << board[0];

	rlutil::resetColor();

	std::cout << " | ";

	if (board[1] == 'X')
		rlutil::setColor(10);
	else if (board[1] == 'O')
		rlutil::setColor(5);

	std::cout << board[1];

	rlutil::resetColor();

	std::cout << " | ";

	if (board[2] == 'X')
		rlutil::setColor(10);
	else if (board[2] == 'O')
		rlutil::setColor(5);

	std::cout << board[2];

	rlutil::resetColor();
	std::cout << " |" << std::endl;
	std::cout << "  -------------" << std::endl;
	std::cout << "2 | ";

	if (board[3] == 'X')
		rlutil::setColor(10);
	else if (board[3] == 'O')
		rlutil::setColor(5);

	std::cout << board[3];

	rlutil::resetColor();

	std::cout << " | ";

	if (board[4] == 'X')
		rlutil::setColor(10);
	else if (board[4] == 'O')
		rlutil::setColor(5);

	std::cout << board[4];

	rlutil::resetColor();

	std::cout << " | ";

	if (board[5] == 'X')
		rlutil::setColor(10);
	else if (board[5] == 'O')
		rlutil::setColor(5);

	std::cout << board[5];

	rlutil::resetColor();

	std::cout << " |" << std::endl;


	std::cout << "  -------------" << std::endl;
	std::cout << "3 | ";

	if (board[6] == 'X')
		rlutil::setColor(10);
	else if (board[6] == 'O')
		rlutil::setColor(5);

	std::cout << board[6];

	rlutil::resetColor();

	std::cout << " | ";

	if (board[7] == 'X')
		rlutil::setColor(10);
	else if (board[7] == 'O')
		rlutil::setColor(5);

	std::cout << board[7];

	rlutil::resetColor();

	std::cout << " | ";

	if (board[8] == 'X')
		rlutil::setColor(10);
	else if (board[8] == 'O')
		rlutil::setColor(5);

	std::cout << board[8];

	rlutil::resetColor();

	std::cout << " |" << std::endl;
	std::cout << "  -------------" << std::endl;
	rlutil::resetColor();
}

bool Board::SpotCheck(char playerInput, int row, int col)
{
	if (playerInput == 'X' || playerInput == 'O' && !gameDone)
	{
		if (row >= 1 && row <= 3)
		{
			int index;
			if (row == 1)
			{
				index = (row + col) - 2;
				if (board[index] == NULL)
					return true;
				else
					return false;
			}
			else if (row == 2)
			{
				index = row + col;
				if (board[index] == NULL)
					return true;
				else
					return false;
			}
			else if (row == 3)
			{
				index = (row + col) + 2;
				if (board[index] == NULL)
					return true;
				else
					return false;
			}
		}
	}
	return false;
}

char Board::CheckVictory(char ty)
{
	int count = 0;

	for (int i = 0; i < boardSize; i++)
	{
		if (board[i] != NULL)
		{
			count++;
		}
		else
			break;
	}

	if (ty == 'X' || ty == 'O')
	{
		if (board[0] == ty && board[1] == ty && board[2] == ty)
		{
			return ty;
		}

		else if (board[3] == ty && board[4] == ty && board[5] == ty)
		{
			return ty;
		}

		else if (board[6] == ty && board[7] == ty && board[8] == ty)
		{
			return ty;
		}

		else if (board[0] == ty && board[3] == ty && board[6] == ty)
		{
			return ty;
		}

		else if (board[1] == ty && board[4] == ty && board[7] == ty)
		{
			return ty;
		}

		else if (board[2] == ty && board[5] == ty && board[8] == ty)
		{
			return ty;
		}

		else if (board[0] == ty && board[4] == ty && board[8] == ty)
		{
			return ty;
		}

		else if (board[2] == ty && board[4] == ty && board[6] == ty)
		{
			return ty;
		}
	}
	if (count == boardSize)
		return 'D';
	else
		return NULL;
}

void Board::GameFinished(char ty)
{
	if (CheckVictory(ty) == 'X')
	{
		gameDone = true;
		rlutil::setColor(10);
		std::cout << "***Winner is player X!***\n" << std::endl;
	}
	else if (CheckVictory(ty) == 'O')
	{
		gameDone = true;
		rlutil::setColor(5);
		std::cout << "***Winner is player O!***\n" << std::endl;
	}
	else if (CheckVictory(ty) == 'D')
	{
		gameDone = true;
		rlutil::setColor(12);
		std::cout << "***DRAW!***\n" << std::endl;
	}
}

void Board::NextTurn()
{
	if (!gameDone || !gameWon)
	{
		if (currentPlayer == 'X')
			currentPlayer = 'O';
		else if (currentPlayer == 'O')
			currentPlayer = 'X';
	}
}

char* Board::GetBoard()
{
	return board;
}
