#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include"Board.h"
using namespace std;

void main()
{
	Board board;
	board.printBoard();
	cout << endl;
	board.setShipsHoritonally(3, 4, Battleship);
	board.printBoard();
	cout << endl;
	board.setShipsVertically(0, 1, Cruiser);
	board.printBoard();
	board.setShipsVertically(4,3,Submarine);
	board.printBoard();
}