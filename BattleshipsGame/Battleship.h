#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

/* 
	- HAR�TANIN MANTI�I - 
+ -1 => Gemi etraf�ndaki bo�luklar
+ 0 => Temiz harita
+ 1 => Gemi
+ 2 => Hit
+ 3 => Miss

	- HAR�TADAK� Y�N MANTI�I -
+ 0 => Dikey y�n
+ 1 => Yatay y�n

	- HAR�TADAK� KOORD�NAT MANTI�I -
+ Oyun haritas�nda de�i�iklik yap�l�rken kullan�lan sat�r s�tun i�lemleri koordinat d�zlemi mant���na g�re �al��maktad�r.
	�r/
		Bir board[y][x] dizisi,
				
					X
			= = = = = = = = = = 
			= = = = = = = = = =
			= = = = = = = = = =
			= = = = = = = = = =
		Y	= = = = = = = = = =  g�sterildi�i gibi �al��maktad�r.
			= = = = = = = = = =
			= = = = = = = = = =
			= = = = = = = = = =
			= = = = = = = = = =
			= = = = = = = = = =
*/

class Battleship
{
private:
	int player[10][10], computer[10][10];
	int ships[5] = { 5/*Carrier*/, 4/*Battleship*/, 3/*Cruiser*/, 3/*Submarine*/, 2/*Destroyer*/};
	int comScore, plyScore;
public:
	Battleship();
	void printBoards();
	void setComputerShips();
	void setPlayerShips();
	bool areCoordinatesInRange(int x, int y);
	void setShipsHorizontally(int board[10][10], int x, int y, int shipSize);
	void setShipsVertically(int board[10][10], int x, int y, int shipSize);
	bool isShipOutofBoard(int x, int y, int shipSize, int direction);
	bool isOverlapping(int board[10][10], int x, int y, int shipSize, int direction);
	void startGame();
	bool playersTurn();
	bool computersTurn();
	bool isHitOrMissed(int board[10][10], int x, int y);
	~Battleship();
};
