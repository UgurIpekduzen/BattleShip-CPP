#include "Game.h"

Game::Game() {
	totalPrize = 0;
	readQuestions();
	readScoreboard();
}

void Game::startGame()
{
	system("CLS");
	cout << "Who Wants To Be A Millionare?" << endl
		<< "1 - Start Game" << endl
		<< "2 - Scoreboard" << endl
		<< "0 - Exit Game" << endl;

	switch (_getch()) {
	case StartGame: selectQuestion(); break;
	case ScoreBoard:
		system("CLS");
		printScoreboard();
		cout << "0 - Back to Menu" << endl;
		switch (_getch()) case ExitGameOrBack: startGame(); break;
		break;
	case ExitGameOrBack: exit(0); break; //Oyundan çýkar.
	}
}

void Game::readScoreboard() {
	string name, score;
	ifstream scoreboardFile;
	scoreboardFile.open("scoreboard.txt");

	while (!scoreboardFile.eof()) {
		getline(scoreboardFile, name, ',');
		getline(scoreboardFile, score, '\n');
		if (name != "" && score != "") scoreboard.push_back(Scoreboard(name, score));
	}
}

void Game::saveScoreboard() {
	ofstream file;
	file.open("scoreboard.txt");
	if(file.is_open())
		for (int i = 0; i < scoreboard.size(); i++)
			if(scoreboard[i].getName() != "" && scoreboard[i].getScore() != "")
				file << scoreboard[i].getName() << "," << scoreboard[i].getScore() << endl;
	file.close();
}

void Game::readQuestions() {
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

void Game:: printQuestion(int & levelIndex, int questionIndex, array<string, 4> & arr) {
	system("CLS");
	cout << levelIndex + 1 << ") " << questions[levelIndex][questionIndex].getQuestion() << "?"<< endl << endl;
	for (int i = 0; i < choiceNames.size(); i++) {
		cout << choiceNames[i] << ") " << arr[i];
		if (i % 2 == 0) cout << setw(7);
		else cout << endl << endl;
	}
}

void Game::printScoreboard()
{
	Sleep(3000);
	system("CLS");
	cout << "Name" << setw(13) << "Score" << endl;
	for (int i = 0; i < scoreboard.size(); i++)
		cout << scoreboard[i].getName() << setw(13) << scoreboard[i].getScore() << endl;
}

void Game::addToScoreboard()
{
	string name;
	cout << endl << "Name: "; cin >> name;
	scoreboard.push_back(Scoreboard(name, to_string(totalPrize)));
	printScoreboard();

	cout << "1 - Play Again" << endl
		<< "0 - Exit Game" << endl;

	switch (_getch()) {
	case StartGame: selectQuestion(); break;
	case ExitGameOrBack:
		saveScoreboard();
		exit(0);//Oyundan çýkar.
		break; 
	}
}

void Game::selectQuestion() {
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
		levelCount = leaveGame(levelCount);
		
		if (levelCount != 12) {
			if (lifelineCount != 0) {
				cout << "Before answer the question, please make a choice: \n";
				lifelineCount = selectLifeline(levelCount, randQuestion, choices, lifelineCount, areLifelinesUsed);
			} else {
				cout << "You have no lifeline." << endl;
				selectChoice(levelCount, randQuestion, 0);
			}
		} else addToScoreboard();
	}
}

void Game::selectChoice(int & levelIndex, int questionIndex, int choiceSelect) {
	//Kullanýcý, tanýmlanan tuþlar haricinde bir tuþa basarsa, doðru tuþ basýlana kadar program devam etmez.
	if (choiceSelect == 0) {
		choiceSelect = _getch();
		while (!isSelected(choiceSelect, Choice)) {
			cerr << "You pushed a wrong button, try again." << endl;
			choiceSelect = _getch();
		}
	}
	//Kullanýcý þýk seçerken, büyük yada küçük harf farketmeksizin þýklarý tuþlayabilir.
	//ASCII tablosunda büyük harf kodlarýnýn 32 fazlasý küçük harf kodlarýna eþittir. 
	if (choiceSelect == questions[levelIndex][questionIndex].getCorrectChoice().at(0) || choiceSelect == questions[levelIndex][questionIndex].getCorrectChoice().at(0) + 32) {
		totalPrize = moneyPrize[levelIndex];
		if (levelIndex == 11) {
			cout << "Answer: " << questions[levelIndex][questionIndex].getCorrectChoice() << endl
				<< "Congratulations! You win!" << endl
				<< "Prize: " << totalPrize << endl;
			addToScoreboard();
		} else {
			cout << "Answer: " << questions[levelIndex][questionIndex].getCorrectChoice() << endl
			    << "Congratulations! Next question." << endl
				<< "Prize: " << totalPrize << endl;
			Sleep(3000);
		}
	} else {
		cout << "Answer: " << questions[levelIndex][questionIndex].getCorrectChoice() << endl
		    << "You lose!" << endl
			<< "Prize: " << totalPrize << endl;
		levelIndex = 12; //levelIndex'in 12 olmasý, selectQuestion() metodu içindeki döngüyü bitirir, oyun biter.
		addToScoreboard();
	}
}

int Game::selectLifeline(int & levelIndex, int questionIndex, array<string, 4> & arr, int count, array<bool, 2> & bools) {
	int lifelineSelect = 0;
	cout << (bools[FiftyFifty] != true ? "1 - 50/50 \n" : "1 - USED\n");
	cout << (bools[DoubleDip] != true ? "2 - Double Dip \n" : "2 - USED\n");
	cout << "0 - Continue" << endl;
	//Kullanýcý, tanýmlanan tuþlar haricinde bir tuþa basarsa, doðru tuþ basýlana kadar program devam etmez.
	lifelineSelect = _getch();
	while (!isSelected(lifelineSelect, Lifeline)) {
		cerr << "You pushed a wrong button, try again." << endl;
		lifelineSelect = _getch();
	}
	//Kullanýcý þýk seçerken, büyük yada küçük harf farketmeksizin þýklarý tuþlayabilir.
	//ASCII tablosunda büyük harf kodlarýnýn 32 fazlasý küçük harf kodlarýna eþittir. 
	if (lifelineSelect == lifelineButtons[1]) {
		bools[FiftyFifty] = fiftyFiftyLifeline(levelIndex, questionIndex, arr);
		return count - 1;
	} else if (lifelineSelect == lifelineButtons[2]) { 
		bools[DoubleDip] = doubleDipLifeline(levelIndex, questionIndex, arr);
		return count - 1;
	} if (lifelineSelect == lifelineButtons[0]) {
		cout << "Which choice?" << endl;
		selectChoice(levelIndex, questionIndex, 0);
		return count;
	}
}

bool Game::isSelected(int num, int mode) { 
	switch (mode) {
	case Choice: for (int i = 0; i < choiceButtons.size(); i++) if (num == choiceButtons[i]) return true; break;
	case Lifeline: for (int i = 0; i < lifelineButtons.size(); i++) if (num == lifelineButtons[i]) return true; break;
	case LeaveOrContinue: for (int i = 0; i < leaveOrContinueButtons.size(); i++) if (num == leaveOrContinueButtons[i]) return true; break;
	}
 	return false;
}

bool Game::isEqualToCorrectChoice(string correctChoice, int firstIndex, int secondIndex) { return (choiceNames[firstIndex] == correctChoice || choiceNames[secondIndex] == correctChoice) ? true : false; }

bool Game::fiftyFiftyLifeline(int & levelIndex, int questionIndex, array<string, 4> & arr) {
	int firstChoice, secondChoice;
	do {
		firstChoice = rand() % 4;
		secondChoice = rand() % 4;
	} while (firstChoice == secondChoice || isEqualToCorrectChoice(questions[levelIndex][questionIndex].getCorrectChoice(), firstChoice, secondChoice));

	arr[firstChoice] = arr[secondChoice] = "		";
	printQuestion(levelIndex, questionIndex, arr);
	selectChoice(levelIndex, questionIndex, 0);
	return true;
}

bool Game::doubleDipLifeline(int & levelIndex, int questionIndex, array<string, 4> & arr) {
	string firstGuess, secondGuess;
	do {
		cout << "First Guess: "; cin >> firstGuess; cout << endl;
		cout << "Second Guess: "; cin >> secondGuess; cout << endl;
	} while (firstGuess == secondGuess || !isSelected(firstGuess.at(0), Choice) || !isSelected(secondGuess.at(0), Choice));

	if(firstGuess.at(0) == questions[levelIndex][questionIndex].getCorrectChoice().at(0) || firstGuess.at(0) == questions[levelIndex][questionIndex].getCorrectChoice().at(0) + 32)
		selectChoice(levelIndex, questionIndex, firstGuess.at(0));
	else selectChoice(levelIndex, questionIndex, secondGuess.at(0));
	
	return true;
}

int Game::leaveGame(int levelIndex)
{
	int choice;
	if (levelIndex == 0) cout << "0 TL ";
	else if (levelIndex > 0 && levelIndex <= 6) cout << "1000 TL ";
	else if (levelIndex > 6) cout << "15000 TL ";

	cout << "prize are quaranteed" << endl
		<< "1 - Leave Game" << endl
		<< "0 - Countinue" << endl;
	
	do choice = _getch();
	while (!isSelected(choice, LeaveOrContinue));
	if (choice == lifelineButtons[1])
	{
		cout << "You Lose!" << endl;
		if (levelIndex == 0) {
			totalPrize = 0;
			levelIndex = 12;
			cout << "Prize: " << totalPrize << endl;
		} else if (levelIndex > 0 && levelIndex <= 5) { 
			totalPrize = 1000;
			levelIndex = 12;
			cout << "Prize: " << totalPrize << endl;
		} else if (levelIndex > 5) {
			totalPrize = 15000;
			levelIndex = 12;
			cout << "Prize: " << totalPrize << endl;
		}
	} //levelIndex'in 12 olmasý, selectQuestion() metodu içindeki döngüyü bitirir, oyun biter.
	return levelIndex;
}

Game::~Game()
{
}
