#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
class Board
{
private:
	int board[10][10];
	int ships[5] = { 5/* Carrier */, 4/*Battleship*/, 3/*Cruiser*/, 3/*Submarine*/, 2/*Destroyer*/};
public:
	Board();
	void setShipsHoritonally(int coorX, int coorY, int shipSize);
	void setShipsVertically(int coorX, int coorY, int shipSize);
	void printBoard();
	void setComputerShips();
	void hitTheShip();
	void setPlayerShips();
	bool isShipOutofBoard(int coorX, int coorY, int shipSize, int direction);
	bool isOverlapping(int coorX, int coorY, int shipSize, int direction);
	~Board();
};
