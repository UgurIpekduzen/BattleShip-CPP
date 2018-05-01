#include "Scoreboard.h"



Scoreboard::Scoreboard() { name = score = ""; }

Scoreboard::Scoreboard(string name, string score)
{
	setName(name);
	setScore(score);
}

void Scoreboard::setName(string name) { this->name = name; }
void Scoreboard::setScore(string score) { this->score = score; }

string Scoreboard::getName() { return name; }
string Scoreboard::getScore() { return score; }


Scoreboard::~Scoreboard()
{
}
