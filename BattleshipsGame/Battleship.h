#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

/* 
	- HARÝTANIN MANTIÐI - 
+ -1 => Gemi etrafýndaki boþluklar
+ 0 => Temiz harita
+ 1 => Gemi
+ 2 => Hit
+ 3 => Miss

	- HARÝTADAKÝ YÖN MANTIÐI -
+ 0 => Dikey yön
+ 1 => Yatay yön

	- HARÝTADAKÝ KOORDÝNAT MANTIÐI -
+ Oyun haritasýnda deðiþiklik yapýlýrken kullanýlan satýr sütun iþlemleri koordinat düzlemi mantýðýna göre çalýþmaktadýr.
	Ör/
		Bir board[y][x] dizisi,
				
					X
			= = = = = = = = = = 
			= = = = = = = = = =
			= = = = = = = = = =
			= = = = = = = = = =
		Y	= = = = = = = = = =  gösterildiði gibi çalýþmaktadýr.
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
