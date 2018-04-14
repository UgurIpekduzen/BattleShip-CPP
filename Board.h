#pragma once
#include <iostream>
#include <string>

using namespace std;
class Board
{
private:
	int board[10][10];
public:
	Board();
	void setShipsHoritonally(int coorX, int coorY, int shipSize);
	void setShipsVertically(int coorX, int coorY, int shipSize);
	void printBoard();
	~Board();
};

enum Ships { Carrier = 5, Battleship = 4, Cruiser = 3, Submarine = 3, Destroyer = 2 };
