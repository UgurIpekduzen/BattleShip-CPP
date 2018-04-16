#include "Battleship.h"

Battleship::Battleship()
{
	plyScore = comScore = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0;j < 10; j++) 
			player[i][j] = computer[i][j] = 0;			
}

void Battleship::setShipsHoritonally(int board[10][10], int coorX, int coorY, int shipSize)
{
	for (int i = coorY - 1; i <= coorY + 1; i++)
		for (int j = coorX - 1; j <= coorX + shipSize; j++)
			if (i < 0 || i > 9 || j < 0 || j > 9) continue;
			else board[i][j] = (i == coorY - 1 || i == coorY + 1 || j == coorX - 1 || j == coorX + shipSize) ? -1 : 1;
}

void Battleship::printBoards()
{
	system("CLS");
	cout << setw(11) << "PLAYER" << setw(32) << "COMPUTER" << endl;
	cout << "    ";
	for (int i = 0;i < 10; i++) cout << setw(2) << i + 1;
	cout << "	  ";
	for (int i = 0;i < 10; i++) cout << setw(2) << i + 1;
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << setw(2) << i + 1 << setw(5);
		for (int j = 0;j < 10; j++) {
			if (player[i][j] == -1 || player[i][j] == 0) cout << "= ";
			else if (player[i][j] == 1) cout << "> ";
			else if (player[i][j] == 2) cout << "H ";
			else if (player[i][j] == 3) cout << "M ";
		}
		cout << setw(7) << i + 1 <<setw(5);
		for (int j = 0;j < 10; j++) {
			if (computer[i][j] == -1 || computer[i][j] == 0 || computer[i][j] == 1) cout << "= ";
			//else if (computer[i][j] == 1) cout << "> ";
			else if (computer[i][j] == 2) cout << "H ";
			else if (computer[i][j] == 3) cout << "M ";
		}
		cout << endl;
	}
	cout << setw(12) << "Score: " << plyScore << setw(29) << "Score: " << comScore << endl;
}

void Battleship::setComputerShips()
{
	int coorX, coorY, direction;
	for (int i = 0; i < sizeof(ships) / sizeof(ships[0]); i++) {
		direction = rand() % 2;
		do {
			srand(time(NULL));
			coorX = rand() % 10;
			coorY = rand() % 10;
		} while (isOverlapping(computer,coorX, coorY, ships[i], direction) || isShipOutofBoard(coorX, coorY, ships[i], direction));
		
		if (direction == 0) setShipsVertically(computer, coorX, coorY, ships[i]);
		else setShipsHoritonally(computer, coorX, coorY, ships[i]);
	}
}

void Battleship::startGame()
{
	do{
		if (playersTurn() == true) plyScore++;
		if (computersTurn() == true) comScore++;
	} while (plyScore != 9 && comScore != 9);

	system("CLS");
	if (plyScore == 9) cout << "YOU WON!";
	else cout << "YOU LOSE";
	cout << endl;
}

bool Battleship::playersTurn()
{
	int coorX, coorY;
	
	do {
		printBoards();
		cout << "Enter X and Y coordinants: "; cin >> coorX; cin >> coorY;
	} while (isHitOrMissed(computer, coorX - 1, coorY - 1) || (coorX - 1 < 0 || coorX - 1 > 9) || (coorY - 1 < 0 || coorY - 1 > 9));
	
	computer[coorY - 1][coorX - 1] = (computer[coorY - 1][coorX - 1] == 1) ? 2 : 3;
	
	return (computer[coorY - 1][coorX - 1] == 2) ? true : false;
}

bool Battleship::computersTurn()
{
	int coorX, coorY;

	do {
		printBoards();
		srand(time(NULL));
		coorX = rand() % 10;
		coorY = rand() % 10;
	} while (isHitOrMissed(player, coorX, coorY) || (coorX < 0 || coorX > 9) || (coorY < 0 || coorY > 9));

	player[coorY][coorX] = (player[coorY][coorX] == 1) ? 2 : 3;

	return (player[coorY][coorX] == 2) ? true : false;
}

void Battleship::setPlayerShips()
{
	int coorX, coorY, direction;
	for (int i = 0; i < sizeof(ships) / sizeof(ships[0]); i++) {
		do {
			printBoards();
			cout << "Direction: "; cin >> direction;
		} while (direction < 0 || direction > 1);
		
		do {
			do { 
				printBoards();
				cout << "Enter X and Y coordinants: "; cin >> coorX; cin >> coorY;
			} while ((coorX - 1 < 0 || coorX - 1 > 9) || (coorY - 1 < 0 || coorY - 1 > 9));
		} while (isShipOutofBoard(coorX - 1, coorY - 1, ships[i], direction) || isOverlapping(player, coorX - 1, coorY - 1, ships[i], direction) );

		if (direction == 0) setShipsVertically(player, coorX - 1, coorY - 1, ships[i]);
		else setShipsHoritonally(player, coorX - 1, coorY - 1, ships[i]);
		printBoards();
	}
}

bool Battleship::isShipOutofBoard(int coorX, int coorY, int shipSize, int direction)
{
	if (direction == 0) return (coorY + shipSize - 1 < 10) ? false : true;
	else return (coorX + shipSize - 1 < 10) ? false : true;
}

void Battleship::setShipsVertically(int board[10][10], int coorX, int coorY, int shipSize)
{ 
	for (int i = coorY - 1; i <= coorY + shipSize; i++)
		for (int j = coorX - 1; j <= coorX + 1; j++)
			if (i < 0 || i > 9 || j < 0 || j > 9) continue;
			else board[i][j] = (i == coorY - 1 || i == coorY + shipSize || j == coorX - 1 || j == coorX + 1) ? -1 : 1;
}

bool Battleship::isOverlapping(int board[10][10], int coorX, int coorY, int shipSize, int direction)
{
	if (direction == 0) {
		for (int i = coorY; i < coorY + shipSize; i++)
				if (board[i][coorX] == -1 || board[i][coorX] == 1) return true;
		return false;
	}
	else {
			for (int j = coorX; j < coorX + shipSize; j++)
				if (board[coorY][j] == -1 || board[coorY][j] == 1) return true;
		return false;
	}
}

bool Battleship::isHitOrMissed(int board[10][10], int x, int y) { return (board[y][x] == 2 || board[y][x] == 3) ? true : false; }

Battleship::~Battleship()
{
}



