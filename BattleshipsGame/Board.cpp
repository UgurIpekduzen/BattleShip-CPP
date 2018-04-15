#include "Board.h"

Board::Board()
{
	for (int boardY = 0; boardY < 10; boardY++)
		for (int boardX = 0;boardX < 10; boardX++)
			board[boardY][boardX] = 0;
}

void Board::setShipsHoritonally(int coorX, int coorY, int shipSize)
{
	for (int i = coorY - 1; i <= coorY + 1; i++)
		for (int j = coorX - 1; j <= coorX + shipSize; j++)
			if (i < 0 || i >= 10 || j < 0 || j >= 10) continue;
			else board[i][j] = (i == coorY - 1 || i == coorY + 1 || j == coorX - 1 || j == coorX + shipSize) ? -1 : 1;
}

void Board::printBoard()
{
	system("CLS");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0;j < 10; j++)
		{
			if (board[i][j] == -1 || board[i][j] == 0) cout << "= ";
			else if (board[i][j] == 1) cout << "> ";
			else if (board[i][j] == 2) cout << "H ";
			else if (board[i][j] == 3) cout << "M ";
		}
		cout << endl;
	}
}

void Board::setComputerShips()
{
	int coorX, coorY, direction;
	for (int i = 0; i < sizeof(ships) / sizeof(ships[0]); i++)
	{
		direction = rand() % 2;
		do
		{
			srand(time(NULL));
			coorX = rand() % 10;
			coorY = rand() % 10;
		} while (isOverlapping(coorX, coorY, ships[i], direction) || isShipOutofBoard(coorX, coorY, ships[i], direction));
		
		if (direction == 0) setShipsVertically(coorX, coorY, ships[i]);
		else setShipsHoritonally(coorX, coorY, ships[i]);
	}
}

void Board::hitTheShip()
{
	int coorX, coorY, score = 0;
	do {
		 do
		 {
			printBoard();
			cout << "Enter X and Y coordinants: "; cin >> coorX; cin >> coorY;
		 } while ((coorX < 0 || coorX > 10) || (coorY < 0 || coorY > 10));
		 board[coorY][coorX] = (board[coorY][coorX] == 1) ? 2 : 3; 
		score++;
		printBoard();
	} while (score != 9);
}

void Board::setPlayerShips()
{
	int coorX, coorY, direction;
	for (int i = 0; i < sizeof(ships) / sizeof(ships[0]); i++)
	{
		do 
		{
			printBoard();
			cout << "Direction: "; cin >> direction;
		}
		while (direction < 0 || direction > 1);
		do
		{
			do 
			{ 
				printBoard();
				cout << "Enter X and Y coordinants: "; cin >> coorX; cin >> coorY;
			} while ((coorX < 0 || coorX > 10) || (coorY < 0 || coorY > 10));
		} while (isOverlapping(coorX, coorY, ships[i], direction) || isShipOutofBoard(coorX, coorY, ships[i], direction));

		if (direction == 0) setShipsVertically(coorX, coorY, ships[i]);
		else setShipsHoritonally(coorX, coorY, ships[i]);
		printBoard();
	}
}

bool Board::isShipOutofBoard(int coorX, int coorY, int shipSize, int direction)
{
	if (direction == 0) return (coorY + shipSize - 1 < 10) ? false : true;
	else return (coorX + shipSize - 1 < 10) ? false : true;
}

void Board::setShipsVertically(int coorX, int coorY, int shipSize) 
{ 
	for (int i = coorY - 1; i <= coorY + shipSize; i++)
		for (int j = coorX - 1; j <= coorX + 1; j++)
			if (i < 0 || i >= 10 || j < 0 || j >= 10) continue;
			else board[i][j] = (i == coorY - 1 || i == coorY + shipSize || j == coorX - 1 || j == coorX + 1) ? -1 : 1;
}

bool Board::isOverlapping(int coorX, int coorY, int shipSize, int direction)
{
	if (direction == 0)
	{
		for (int i = coorY - 1; i < coorY + shipSize; i++)
				if (board[i][coorX] == -1 || board[i][coorX] == 1) return true;
		return false;
	}
	else
	{
			for (int j = coorX - 1; j <= coorX + shipSize; j++)
				if (board[coorY][j] == -1 || board[coorY][j] == 1) return true;
		return false;
	}
}

Board::~Board()
{
}



