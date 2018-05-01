#pragma once
#include "Question.h"
#include "Scoreboard.h"
#include <conio.h>
#include <vector>
#include <ctime>
#include<fstream>
#include<iomanip>
#include<string>
#include <array>
#include<Windows.h>

enum choiceIndex { A, B, C, D };
enum lifelineIndex { FiftyFifty, DoubleDip };
enum choiceOrLifeline { Choice, Lifeline, LeaveOrContinue };
enum MenuScreen { ExitGameOrBack = 48, StartGame = 49, ScoreBoard = 50 };
class Game
{
private:
	vector<vector<Question>> questions;
	vector<Scoreboard> scoreboard;
	array<int, 9> choiceButtons = { /*A*/65, /*B*/66, /*C*/67, /*D*/68, /*a*/97, /*b*/98, /*c*/99, /*d*/100 }; //ASCII Karakterleri
	array<int, 4> lifelineButtons = {/*0*/48, /*1*/49, /*2*/50 }; //ASCII Karakterleri
	array<int, 2> leaveOrContinueButtons = { 48, 49 };
	array<string, 4> choiceNames = { "A", "B", "C", "D" };
	array<int, 12> moneyPrize = {
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
	void startGame();
	//Dosya Okuma Yazma Metodlarý
	void readScoreboard();
	void saveScoreboard();
	void readQuestions();
	//Yazdýrma Ekleme Metodlarý
	void printQuestion(int & levelIndex, int questionIndex, array<string, 4> & arr);
	void printScoreboard();
	void addToScoreboard();
	//Ana Metodlar
	void selectQuestion();
	void selectChoice(int & levelIndex, int questionIndex, int choiceSelect);
	int selectLifeline(int & levelIndex, int questionIndex, array<string, 4> & arr, int count, array<bool, 2> & bools);
	//Yardýmcý Metodlar
	bool isSelected(int num, int mode);
	bool isEqualToCorrectChoice(string correctChoice, int firstIndex, int secondIndex);
	//Joker Haklarý Metodlarý
	bool fiftyFiftyLifeline(int & levelIndex, int questionIndex, array<string, 4> & arr);
	bool doubleDipLifeline(int & levelIndex, int questionIndex, array<string, 4> & arr);
	int leaveGame(int levelIndex);
	~Game();
};

