#include "Battleship.h"

void main()
{
	/* - OYUN A�ILIRKEN - 
	+ Oyun a��ld���nda bilgisayar tahtas� olu�turulurken, rasgele de�erler verilmektedir.
	+ Bu verilen de�erlere uygun yerle�tirme i�lemlerinde yap�lan kontroller ve hesaplamalar uzun s�rebilmektedir.
	+ Bu yerle�tirme i�lemleri bitti�inde, her iki tahta ekranda yazd�r�l�r, sonra oyuncu kendi tahtas�nda gemileri yerle�tirmeye ba�lar.
	*/
	Battleship battleship;
	battleship.setComputerShips();
	battleship.setPlayerShips();
	battleship.startGame();
}

/*
	- HAZIRLAYANLAR -
+ 150101045 - U�ur �PEKD�ZEN
+ 160101001 - �eyma Nur PEHL�VAN
+ 160101041 - Mustafa Furkan �EN
*/