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
	for (int levelCount = 0; levelCount < 12; levelCount++) {
		while (questionFile.good()) {
			while (getline(questionFile, questionID, ',')) {
				getline(questionFile, levelNo, ',');
				
				if (levelNo == to_string(levelCount + 1)) break;
				else getline(questionFile, temp, '\n');
			}
			getline(questionFile, question, '?');//Ýçinde ',' barýndýran soru metinleri için, soru iþaretine(?) kadar olan kýsmý alýr.
			getline(questionFile, temp, ',');// '?' ise boþ bir deðere atýlýr.
			getline(questionFile, choiseA, ',');
			getline(questionFile, choiseB, ',');
			getline(questionFile, choiseC, ',');
			getline(questionFile, choiseD, ',');
			getline(questionFile, correctChoise, ',');
			getline(questionFile, programID, '\n');
			
			if(questionID != "") questions[levelCount].push_back(Question(questionID, levelNo, question, choiseA, choiseB, choiseC, choiseD, correctChoise));
		}
		//Dosyanýn en baþa dönmesi için gerekli komutlar.
		questionFile.clear();
		questionFile.seekg(0, ios::beg);
	}
}

void Game:: printQuestion(int levelIndex, int questionIndex, array<string, 4> & arr)
{
	array<string, 4> choiceNames = { "A", "B", "C", "D" };

	cout << levelIndex + 1 << ") " << questions[levelIndex][questionIndex].getQuestion() << "?"<< endl << endl;
	for (int i = 0; i < choiceNames.size(); i++) {
		cout << choiceNames[i] << ") " << arr[i];
		if (i % 2 == 0) cout << setw(7);
		else cout << endl << endl;
	}
}

void Game::selectQuestion()
{
	int randQuestion, lifelineCount = 2;
	array<bool,2> areLifelinesUsed = { false, false };
	array<string,4> choices;
	for (int levelCount = 0; levelCount < 12; levelCount++) {
		
		srand(time(NULL));
		randQuestion = rand() % questions[levelCount].size();

		choices[A] = questions[levelCount][randQuestion].getChoiceA();
		choices[B] = questions[levelCount][randQuestion].getChoiceB();
		choices[C] = questions[levelCount][randQuestion].getChoiceC();
		choices[D] = questions[levelCount][randQuestion].getChoiceD();

		printQuestion(levelCount, randQuestion, choices);
		/*if (lifelineCount != 0) lifelineCount = selectLifeline(levelCount, randQuestion, choices, lifelineCount, areLifelinesUsed);
		else cout << "Hic joker hakkiniz kalmamistir" << endl;*/
		selectChoice(levelCount, randQuestion, choices);
	}
}

void Game::selectChoice(int & levelIndex, int questionIndex, array<string, 4> & arr)
{
	int choiceSelect = 0;
	//Kullanýcý, tanýmlanan tuþlar haricinde bir tuþa basarsa, doðru tuþ basýlana kadar program devam etmez.
	while (!isSelected(choiceSelect, Choise)) cerr << "Yanlis bir tusa bastiniz, lutfen tekrar deneyiniz" << endl;
	//Kullanýcý þýk seçerken, büyük yada küçük harf farketmeksizin þýklarý tuþlayabilir.
	//ASCII tablosunda büyük harf kodlarýnýn 32 fazlasý küçük harf kodlarýna eþittir. 
	if (choiceSelect == questions[levelIndex][questionIndex].getCorrectChoice().at(0) ||
		choiceSelect == questions[levelIndex][questionIndex].getCorrectChoice().at(0) + 32) {

		totalPrize = moneyPrize[levelIndex];
		if (levelIndex == 12) {
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
		levelIndex = 12;
	}
}

int Game::selectLifeline(int levelIndex, int questionIndex, array<string, 4> & arr, int count, array<bool, 2> & bools)
{
	int lifelineSelect = 0;

	cout << "1 - 50/50 Joker Hakký" << endl
		<< "2 - Double Dip Joker Hakký" << endl
		<< "0 - Devam Et" << endl;
	//Kullanýcý, tanýmlanan tuþlar haricinde bir tuþa basarsa, doðru tuþ basýlana kadar program devam etmez.
	while (!isSelected(lifelineSelect, Lifeline)) cerr << "Yanlis bir tusa bastiniz, lutfen tekrar deneyiniz" << endl;
	//Kullanýcý þýk seçerken, büyük yada küçük harf farketmeksizin þýklarý tuþlayabilir.
	//ASCII tablosunda büyük harf kodlarýnýn 32 fazlasý küçük harf kodlarýna eþittir. 
	if (lifelineSelect == lifelineButtons[0]) {
		return count;
	}
	else if (lifelineSelect == lifelineButtons[1]) {

		bools[FiftyFifty] = fiftyFiftyLifeline(levelIndex, questionIndex, arr);
		return count - 1;
	}
	else if (lifelineSelect == lifelineButtons[2]) { 
		bools[DoubleDip] = doubleDipLifeline(levelIndex, questionIndex, arr);
		return count - 1;
	}
}

bool Game::isSelected(int & num, int choiceOrlifeline)
{ 
	num = _getch();
	switch (choiceOrlifeline)
	{
		case Choise: for (int i = 0; i < choiceButtons.size(); i++) if (num == choiceButtons[i]) return true; break;
		case Lifeline: for (int i = 0; i < lifelineButtons.size(); i++) if (num == lifelineButtons[i]) return true; break;
	}
	return false;
}

bool Game::fiftyFiftyLifeline(int levelIndex, int questionIndex, array<string, 4> & arr)
{
	int firstChoice, secondChoice;
	do {
		firstChoice = rand() % 4;
		secondChoice = rand() % 4;
	} while (arr[firstChoice] == questions[levelIndex][questionIndex].getCorrectChoice() 
			|| arr[secondChoice] == questions[levelIndex][questionIndex].getCorrectChoice() 
			|| firstChoice == secondChoice);

	arr[firstChoice] = arr[secondChoice] = "			";
	selectChoice(levelIndex, questionIndex, arr);
	return true;
}

bool Game::doubleDipLifeline(int levelIndex, int questionIndex, array<string, 4> & arr)
{
	int firstGuess, secondGuess;
	do {
		cout << "First Guess: "; firstGuess = _getch();
		cout << "Second Guess: "; secondGuess = _getch();
	} while (firstGuess == secondGuess || !isSelected(firstGuess, Lifeline) || !isSelected(secondGuess, Lifeline));

	return true;
}

Game::~Game()
{
}
