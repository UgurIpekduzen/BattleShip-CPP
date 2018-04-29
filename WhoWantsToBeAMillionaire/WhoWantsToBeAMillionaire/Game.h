#pragma once
#include "Question.h"
#include <conio.h>
#include <vector>
#include <ctime>
#include<fstream>
#include<iomanip>
#include<string>

class Game
{
private:
	vector<vector<Question>> questions;
	int choises[8] = { /*A*/65, /*B*/66, /*C*/67, /*D*/68, /*a*/97, /*b*/98, /*c*/99, /*d*/100 }; //ASCII Karakterleri
	int moneyPrize[12] = {
		/*Level1*/ 500,
		/*Level2*/ 1000,
		/*Level3*/ 2000,
		/*Level4*/ 3000,
		/*Level5*/ 5000,
		/*Level6*/ 7500,
		/*Level7*/ 15000,
		/*Level8*/ 30000,
		/*Level9*/ 60000,
		/*Level10*/ 125000,
		/*Level11*/ 250000,
		/*Level12*/ 1000000 };
	int totalPrize;
public:
	Game();
	void readCSV();
	void printQuestions(int level);
	void selectQuestion();
	bool isTheChoiseSelected(int & num);
	~Game();
};

