#pragma once
#include <iostream>

using namespace std;
class Question
{
private:
	string questionID, levelNo, question, choiceA, choiceB, choiceC, choiceD, correctChoice;
public:
	Question();

	Question(string questionID, string levelNo, string question, string choiceA, string choiceB, string choiceC, string choiceD, string correctChoice);
	void setQuestionID(string questionID);
	void setLevelNo(string levelNo);
	void setQuestion(string question);
	void setChoiceA(string ChoiceA);
	void setChoiceB(string ChoiceB);
	void setChoiceC(string ChoiceC);
	void setChoiceD(string ChoiceD);
	void setCorrectChoice(string correctChoice);
	
	string getQuestionID();
	string getLevelNo();
	string getQuestion();
	string getChoiceA();
	string getChoiceB();
	string getChoiceC();
	string getChoiceD();
	string getCorrectChoice();

	~Question();
};
