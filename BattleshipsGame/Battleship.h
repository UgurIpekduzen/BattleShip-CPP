#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;
class Battleship
{
private:
	int player[10][10], computer[10][10];
	int ships[5] = { 5/*Carrier*/, 4/*Battleship*/, 3/*Cruiser*/, 3/*Submarine*/, 2/*Destroyer*/};
	int comScore, plyScore;
public:
	Battleship();
	void setShipsHoritonally(int board[10][10], int coorX, int coorY, int shipSize);
	void setShipsVertically(int board[10][10], int coorX, int coorY, int shipSize);
	void printBoards();
	void setComputerShips();
	void startGame();
	bool playersTurn();
	bool computersTurn();
	void setPlayerShips();
	bool isShipOutofBoard(int coorX, int coorY, int shipSize, int direction);
	bool isOverlapping(int board[10][10], int coorX, int coorY, int shipSize, int direction);
	bool isHitOrMissed(int board[10][10], int x, int y);
	~Battleship();
};
