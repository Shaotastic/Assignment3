#include "Board.h"


Board::Board()
{
}


Board::~Board()
{
}

void Board::UpdateBoard(char playerInput, int row, int col)
{
	if (playerInput == 'X' || playerInput == 'O' && !gameDone)
	{
		if (row >= 1 && row <= 3)
		{
			if (row == 1)
			{
				if (board[(row + col) - 2] == NULL)
					board[(row + col) - 2] = playerInput;
			}
			else if (row == 2)
			{
				if (board[row + col] == NULL)
					board[row + col] = playerInput;
			}
			else if (row == 3)
			{
				if (board[(row + col) + 2] == NULL)
					board[row + col + 2] = playerInput;
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
			else if(board[index] != NULL && t == NULL)
			{
				board[index] = NULL;
			}
			CheckVictory(t);
			//system("cls");
			//DisplayBoard();
			//NextTurn();
		}
	}

}

void Board::DisplayBoard()
{
	std::cout << "    1   2   3" << std::endl;
	std::cout << "  -------------" << std::endl;
	std::cout << "1 | " << board[0] << " | " << board[1] << " | " << board[2] << " |" << std::endl;
	std::cout << "  -------------" << std::endl;
	std::cout << "2 | " << board[3] << " | " << board[4] << " | " << board[5] << " |" << std::endl;
	std::cout << "  -------------" << std::endl;
	std::cout << "3 | " << board[6] << " | " << board[7] << " | " << board[8] << " |" << std::endl;
	std::cout << "  -------------" << std::endl;
}

char Board::CheckVictory(char ty)
{
	int count = 0;

	for(int i = 0; i < boardSize; i++)
	{
		if (board[i] != NULL)
		{
			count++;
		}
		else
			break;
	}

	if (count == boardSize)
		return 'D';

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

		else if (board[2] == ty && board[4] == ty && board[7] == ty)
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
		else
			return NULL;
	}
	else
		return NULL;
}

char Board::PotentialVictory(char ty)
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

	if (count == boardSize)
		return 'D';

	if (ty == 'X' || ty == 'O')
	{
		if(board[0] == ty)
		{
		}

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

		else if (board[2] == ty && board[4] == ty && board[7] == ty)
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
		else
			return NULL;
	}
	else
		return NULL;
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

void Board::BoardFull()
{
	for (int i = 0; i < 9; i++)
	{
		if (board[i] == NULL)
			break;
		else
			gameDone = true;
	}

}
