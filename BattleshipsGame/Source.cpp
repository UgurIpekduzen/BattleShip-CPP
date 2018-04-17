#include "Battleship.h"

void main()
{
	/* - OYUN AÇILIRKEN - 
	+ Oyun açýldýðýnda bilgisayar tahtasý oluþturulurken, rasgele deðerler verilmektedir.
	+ Bu verilen deðerlere uygun yerleþtirme iþlemlerinde yapýlan kontroller ve hesaplamalar uzun sürebilmektedir.
	+ Bu yerleþtirme iþlemleri bittiðinde, her iki tahta ekranda yazdýrýlýr, sonra oyuncu kendi tahtasýnda gemileri yerleþtirmeye baþlar.
	*/
	Battleship battleship;
	battleship.setComputerShips();
	battleship.setPlayerShips();
	battleship.startGame();
}

/*
	- HAZIRLAYANLAR -
+ 150101045 - Uður ÝPEKDÜZEN
+ 160101001 - Þeyma Nur PEHLÝVAN
+ 160101041 - Mustafa Furkan ÞEN
*/