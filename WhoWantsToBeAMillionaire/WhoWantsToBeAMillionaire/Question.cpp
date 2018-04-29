#include "Question.h"

Question::Question() { questionID = levelNo = question = choiseA = choiseB = choiseC = choiseD = correctChoise = ""; }

Question::Question(string questionID, string levelNo, string question, string choiseA, string choiseB, string choiseC, string choiseD, string correctChoise)
{
	setQuestionID(questionID);
	setLevelNo(levelNo);
	setQuestion(question);
	setChoiseA(choiseA);
	setChoiseB(choiseB);
	setChoiseC(choiseC);
	setChoiseD(choiseD);
	setCorrectChoise(correctChoise);
}

void Question::setQuestionID(string questionID) { this->questionID = questionID; }
void Question::setLevelNo(string levelNo) { this->levelNo = levelNo; }
void Question::setQuestion(string question) { this->question = question; }
void Question::setChoiseA(string choiseA) { this->choiseA = choiseA; }
void Question::setChoiseB(string choiseB) { this->choiseB = choiseB; }
void Question::setChoiseC(string choiseC) { this->choiseC = choiseC; }
void Question::setChoiseD(string choiseD) { this->choiseD = choiseD; }
void Question::setCorrectChoise(string correctChoise) { this->correctChoise = correctChoise; }

string Question::getQuestionID() { return questionID; }
string Question::getLevelNo() { return levelNo; }
string Question::getQuestion() { return question; }
string Question::getChoiseA() { return choiseA; }
string Question::getChoiseB() { return choiseB; }
string Question::getChoiseC() { return choiseC; }
string Question::getChoiseD() { return choiseD; }
string Question::getCorrectChoise() { return correctChoise; }

Question::~Question()
{
}
