#pragma once
#include <iostream>

using namespace std;

class Scoreboard
{
private:
	string name, score;
public:
	Scoreboard();
	Scoreboard(string name, string score);
	
	void setName(string name);
	void setScore(string score);
	
	string getName();
	string getScore();
	
	~Scoreboard();
};

