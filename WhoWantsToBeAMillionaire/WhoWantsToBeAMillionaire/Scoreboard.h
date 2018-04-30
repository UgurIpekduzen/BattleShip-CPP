#pragma once
#include <iostream>

using namespace std;

class Scoreboard
{
private:
	string name, surname, score;
public:
	Scoreboard();
	Scoreboard(string name, string surname, string score);
	
	void setName(string name);
	void setSurname(string surname);
	void setScore(string score);
	
	string getName();
	string getSurname();
	string getScore();
	
	~Scoreboard();
};

