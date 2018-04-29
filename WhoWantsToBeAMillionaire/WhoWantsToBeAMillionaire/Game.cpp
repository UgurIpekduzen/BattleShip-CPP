#include "Game.h"

Game::Game()
{
	totalPrize = 0;
	readCSV();
}

void Game::readCSV()
{
	string questionID, levelNo, question, choiseA, choiseB, choiseC, choiseD, correctChoise, programID, temp;
	ifstream questionFile;
	questions.resize(12); // Toplamda 12 soru sorulacak.
	questionFile.open("question.csv");
	for (int levelCount = 1; levelCount <= 12; levelCount++) {
		while (questionFile.good()) {
			while (getline(questionFile, questionID, ',')) {
				getline(questionFile, levelNo, ',');
				
				if (levelNo == to_string(levelCount)) break;
				else getline(questionFile, temp, '\n');
			}
			getline(questionFile, question, ',');
			getline(questionFile, choiseA, ',');
			getline(questionFile, choiseB, ',');
			getline(questionFile, choiseC, ',');
			getline(questionFile, choiseD, ',');
			getline(questionFile, correctChoise, ',');
			getline(questionFile, programID, '\n');
			
			if(questionID != "") questions[levelCount - 1].push_back(Question(questionID, levelNo, question, choiseA, choiseB, choiseC, choiseD, correctChoise));
		}
		//Dosyanýn en baþa dönmesi için gerekli komutlar.
		questionFile.clear();
		questionFile.seekg(0, ios::beg);
	}
}

void Game:: printQuestions(int level)
{
	for (int i = 0; i <= questions[level - 1].size(); i++) {
		cout << questions[level - 1][i].getQuestionID() << endl
			<< "LEVEL: "<< questions[level - 1][i].getLevelNo() << endl
			<< questions[level - 1][i].getQuestion() << endl
			<< questions[level - 1][i].getChoiseA() << endl
			<< questions[level - 1][i].getChoiseB() << endl
			<< questions[level - 1][i].getChoiseC() << endl
			<< questions[level - 1][i].getChoiseD() << endl
			<< questions[level - 1][i].getCorrectChoise() << endl;
	}
}

void Game::selectQuestion()
{
	int randQuestion, choise;
	for (int levelCount = 1; levelCount <= 12; levelCount++) {
		
		srand(time(NULL));
		randQuestion = rand() % questions[levelCount - 1].size();

		cout << levelCount << ") " << questions[levelCount - 1][randQuestion].getQuestion() << endl << endl
			<< "A) " << questions[levelCount - 1][randQuestion].getChoiseA() << setw(7) << "B) " << questions[levelCount - 1][randQuestion].getChoiseB() << endl << endl
			<< "C) " << questions[levelCount - 1][randQuestion].getChoiseC() << setw(7) << "D) " << questions[levelCount - 1][randQuestion].getChoiseD() << endl;
		
		//Kullanýcý, tanýmlanan tuþlar haricinde bir tuþa basarsa, doðru tuþ basýlana kadar program devam etmez.
		while (!isTheChoiseSelected(choise)) cerr << "Yanlis bir tusa bastiniz, lütfen tekrar deneyiniz" << endl;

		if (choise == questions[levelCount - 1][randQuestion].getCorrectChoise().at(0) ||
			choise == questions[levelCount - 1][randQuestion].getCorrectChoise().at(0) + 32) {
			
			totalPrize = moneyPrize[levelCount - 1];
			if (levelCount == 12) {
				cout << "Tebrikler! Buyuk odulün sahibi sizsiniz." << endl
					<< "Odulunuz: " << totalPrize << endl;
			}
			else {
				cout << "Tebrikler! Bir sonraki soruya gecmeye hak kazandiniz." << endl
					<< "Odulunuz: " << totalPrize << endl;
			}
		}
		else {
			cout << "Kaybettiniz!" << endl
				<< "Odulunuz: " << totalPrize;
			break;
		}
	}
}

bool Game::isTheChoiseSelected(int & num)
{ 
	num = _getch();
	for (int i = 0; i < sizeof(choises) / sizeof(choises[0]); i++) if (num == choises[i]) return true;
	return false;
}

Game::~Game()
{
}
