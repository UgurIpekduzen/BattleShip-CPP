#include "Question.h"

Question::Question() { questionID = levelNo = question = choiceA = choiceB = choiceC = choiceD = correctChoice = ""; }

Question::Question(string questionID, string levelNo, string question, string ChoiceA, string ChoiceB, string ChoiceC, string ChoiceD, string correctChoice)
{
	setQuestionID(questionID);
	setLevelNo(levelNo);
	setQuestion(question);
	setChoiceA(ChoiceA);
	setChoiceB(ChoiceB);
	setChoiceC(ChoiceC);
	setChoiceD(ChoiceD);
	setCorrectChoice(correctChoice);
}

void Question::setQuestionID(string questionID) { this->questionID = questionID; }
void Question::setLevelNo(string levelNo) { this->levelNo = levelNo; }
void Question::setQuestion(string question) { this->question = question; }
void Question::setChoiceA(string ChoiceA) { this->choiceA = ChoiceA; }
void Question::setChoiceB(string ChoiceB) { this->choiceB = ChoiceB; }
void Question::setChoiceC(string ChoiceC) { this->choiceC = ChoiceC; }
void Question::setChoiceD(string ChoiceD) { this->choiceD = ChoiceD; }
void Question::setCorrectChoice(string correctChoice) { this->correctChoice = correctChoice; }

string Question::getQuestionID() { return questionID; }
string Question::getLevelNo() { return levelNo; }
string Question::getQuestion() { return question; }
string Question::getChoiceA() { return choiceA; }
string Question::getChoiceB() { return choiceB; }
string Question::getChoiceC() { return choiceC; }
string Question::getChoiceD() { return choiceD; }
string Question::getCorrectChoice() { return correctChoice; }

Question::~Question()
{
}
