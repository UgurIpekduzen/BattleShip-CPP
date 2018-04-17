#include "Battleship.h"

Battleship::Battleship()
{
	plyScore = comScore = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0;j < 10; j++) 
			player[i][j] = computer[i][j] = 0;	//Her iki oyun tahtas� ba�ta hi�bir de�er atanmam�� olarak olu�turulur.		
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
		//Oyuncunun haritas�
		cout << setw(2) << i + 1 << setw(5);
		for (int j = 0;j < 10; j++) {
			if (player[i][j] == -1 || player[i][j] == 0) cout << "= ";
			else if (player[i][j] == 1) cout << "> ";
			else if (player[i][j] == 2) cout << "H ";
			else if (player[i][j] == 3) cout << "M ";
		}
		//Bilgisayar�n haritas�
		cout << setw(7) << i + 1 <<setw(5);
		for (int j = 0;j < 10; j++) {
			if (computer[i][j] == -1 || computer[i][j] == 0 || computer[i][j] == 1) cout << "= ";
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
		else setShipsHorizontally(computer, coorX, coorY, ships[i]);
	}
}

void Battleship::setPlayerShips()
{
	int coorX, coorY, direction;
	for (int i = 0; i < sizeof(ships) / sizeof(ships[0]); i++) {
		do {
			printBoards();
			cout << "Direction(0 => Vertical, 1 => Horizontal): "; cin >> direction;
		} while (direction < 0 || direction > 1);
		
		do {
			do { 
				printBoards();
				cout << "Enter X and Y coordinates: "; cin >> coorX >> coorY;
			} while (areCoordinatesInRange(coorX - 1, coorY - 1));
		} while (isShipOutofBoard(coorX - 1, coorY - 1, ships[i], direction) || isOverlapping(player, coorX - 1, coorY - 1, ships[i], direction));

		if (direction == 0) setShipsVertically(player, coorX - 1, coorY - 1, ships[i]);
		else setShipsHorizontally(player, coorX - 1, coorY - 1, ships[i]);
		printBoards();
	}
}

//areCoordinatesInRange: Girilen koordinantlar�n dizideki indis de�erlerinin d���nda bir de�er olup olmad���n� kontrol eder.
bool Battleship::areCoordinatesInRange(int x, int y) { return (x < 0 || x > 9) || (y < 0 || y > 9) ? true : false; }

void Battleship::setShipsHorizontally(int board[10][10], int x, int y, int shipSize)
{
	for (int i = y - 1; i <= y + 1; i++)
		for (int j = x - 1; j <= x + shipSize; j++)
			if (i < 0 || i > 9 || j < 0 || j > 9) continue; // Yaz�lacak -1(Bo�luk) de�eri oyun tahtas�n�n d���nda bir koordinata e�itse g�rmezden gelinir.
			else board[i][j] = (i == y - 1 || i == y + 1 || j == x - 1 || j == x + shipSize) ? -1 : 1;
}

void Battleship::setShipsVertically(int board[10][10], int x, int y, int shipSize)
{ 
	for (int i = y - 1; i <= y + shipSize; i++)
		for (int j = x - 1; j <= x + 1; j++)
			if (i < 0 || i > 9 || j < 0 || j > 9) continue; // Yaz�lacak -1(Bo�luk) de�eri oyun tahtas�n�n d���nda bir koordinata e�itse g�rmezden gelinir.
			else board[i][j] = (i == y - 1 || i == y + shipSize || j == x - 1 || j == x + 1) ? -1 : 1;
}

bool Battleship::isShipOutofBoard(int x, int y, int shipSize, int direction)
{//Y�ne ba�l� olarak, girilen koordinatlar� referans noktas� alarak, gemi yerle�tirildi�inde oyun tahtas�n�n d���nda ta��p ta�mad���n� kontrol eder.
	if (direction == 0) return (y + shipSize - 1 < 10) ? false : true;
	else return (x + shipSize - 1 < 10) ? false : true;
}

bool Battleship::isOverlapping(int board[10][10], int x, int y, int shipSize, int direction)
{//Y�ne ba�l� olarak, girilen koordiantlar�n oyun tahtas�nda bir geminin yada bo�lu�un �st�ne binip binmedi�ini kontrol eder.
	if (direction == 0) {
		for (int i = y; i < y + shipSize; i++)
			if (board[i][x] == -1 || board[i][x] == 1) return true;
		return false;
	}
	else {
		for (int j = x; j < x + shipSize; j++)
			if (board[y][j] == -1 || board[y][j] == 1) return true;
		return false;
	}
}

void Battleship::startGame()
{
	do{
		if (playersTurn()) plyScore++; //Oyuncu gemi vurursa (true d�nerse) Oyuncu'nun skorunu artt�r.
		if (computersTurn()) comScore++; //Bilgisayar gemi vurursa (true d�nerse) Bilgisayar'�n skorunu artt�r.
	} while (plyScore != 9 && comScore != 9); 
	//Toplam 17 gemi par�as� var. 17 = 8 + 9 oldu�u i�in skoru 9 olan otomatik olarak ezici �st�nl�k sa�lam�� olur.
	system("CLS");
	if (plyScore == 9) cout << "YOU WON!" << endl << "Score: " << plyScore << endl;
	else cout << "YOU LOSE" << endl << "Score: " << plyScore << endl;
	cout << endl;
}

bool Battleship::playersTurn()
{
	int coorX, coorY;
	//Girilen koordinantlar 0 ile 9 aras�nda olmad��� veya Hit / Miss de�erine e�it oldu�u s�rece d�ng� i�indeki i�lemleri ger�ekle�tirmeye devam eder.
	do {
		printBoards();
		cout << "Enter X and Y coordinates: "; cin >> coorX >> coorY;
	} while (isHitOrMissed(computer, coorX - 1, coorY - 1) || areCoordinatesInRange(coorX - 1, coorY - 1));
	// Girilen koordinatlardaa gemi par�as�na e�it olup olmamas�na g�re Hit veya Miss de�erini atar.
	computer[coorY - 1][coorX - 1] = (computer[coorY - 1][coorX - 1] == 1) ? 2 : 3;
	
	return (computer[coorY - 1][coorX - 1] == 2) ? true : false;
}

bool Battleship::computersTurn()
{
	int coorX, coorY;
	//Girilen koordinantlar 0 ile 9 aras�nda olmad��� veya Hit / Miss de�erine e�it oldu�u s�rece d�ng� i�indeki i�lemleri ger�ekle�tirmeye devam eder.
	do {
		printBoards();
		srand(time(NULL));
		coorX = rand() % 10;
		coorY = rand() % 10;
	} while (isHitOrMissed(player, coorX, coorY) || areCoordinatesInRange(coorX, coorY));

	player[coorY][coorX] = (player[coorY][coorX] == 1) ? 2 : 3;

	return (player[coorY][coorX] == 2) ? true : false;
}

bool Battleship::isHitOrMissed(int board[10][10], int x, int y) { return (board[y][x] == 2 || board[y][x] == 3) ? true : false; }

Battleship::~Battleship() { }



