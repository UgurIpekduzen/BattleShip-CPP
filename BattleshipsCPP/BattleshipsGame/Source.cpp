#include "Battleship.h"

void main()
{
	/* - OYUN AÇILIRKEN - 
	+ Oyun açıldığında bilgisayar tahtası oluşturulurken, rasgele değerler verilmektedir.
	+ Bu verilen değerlere uygun yerleştirme işlemlerinde yapılan kontroller ve hesaplamalar uzun sürebilmektedir.
	+ Bu yerleştirme işlemleri bittiğinde, her iki tahta ekranda yazdırılır, sonra oyuncu kendi tahtasında gemileri yerleştirmeye başlar.
	*/
	Battleship battleship;
	battleship.setComputerShips();
	battleship.setPlayerShips();
	battleship.startGame();
}
