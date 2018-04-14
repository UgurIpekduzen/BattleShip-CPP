#include "Board.h"



Board::Board()
{
	for (int boardX = 0; boardX < 10; boardX++)
		for (int boardY = 0;boardY < 10; boardY++)
			board[boardX][boardY] = 0;
}

void Board::setShipsHoritonally(int coorX, int coorY, int shipSize)
{
	if(board[coorX][coorY] == 0)
	{ 
		for (int i = coorX - 1; i <= coorX + 1; i++)
			for (int j = coorY - 1; j <= coorY + shipSize; j++)
				board[i][j] = (i == coorX - 1 || i == coorX + 1 || j == coorY - 1 || j == coorY + shipSize) ? -1 : 1;
	}
	else cout << "Gemiler üst üste binemez veya aralarýnda boþluk olmak zorundadýr" << endl;
}

void Board::printBoard()
{
	for (int boardX = 0; boardX < 10; boardX++)
	{
		for (int boardY = 0;boardY < 10; boardY++)
			if (board[boardX][boardY] == -1 || board[boardX][boardY] == 0) cout << "= ";
			else if (board[boardX][boardY] == 1) cout << "> ";
		cout << endl;
	}
}

void Board::setShipsVertically(int coorX, int coorY, int shipSize) 
{ 
	if (board[coorX][coorY] == 0)
	{ 
		for (int i = coorX - 1; i <= coorX + shipSize; i++)
			for (int j = coorY - 1; j <= coorY + 1; j++)
				board[i][j] = (i == coorX - 1 || i == coorX + shipSize || j == coorY - 1 || j == coorY + 1) ? -1 : 1;
	}
	else cout << "Gemiler ust uste binemez veya aralarýnda bosluk olmak zorundadýr" << endl;
}

Board::~Board()
{
}
