#pragma once
#include"Question.h"
#include <iostream>

using namespace std;
class Question
{
private:
	string questionID, levelNo, question, choiseA, choiseB, choiseC, choiseD, correctChoise;
public:
	Question();

	Question(string questionID, string levelNo, string question, string choiseA, string choiseB, string choiseC, string choiseD, string correctChoise);
	void setQuestionID(string questionID);
	void setLevelNo(string levelNo);
	void setQuestion(string question);
	void setChoiseA(string choiseA);
	void setChoiseB(string choiseB);
	void setChoiseC(string choiseC);
	void setChoiseD(string choiseD);
	void setCorrectChoise(string correctChoise);
	
	string getQuestionID();
	string getLevelNo();
	string getQuestion();
	string getChoiseA();
	string getChoiseB();
	string getChoiseC();
	string getChoiseD();
	string getCorrectChoise();

	~Question();
};
