#include "Scoreboard.h"



Scoreboard::Scoreboard() { name = surname = score = ""; }

Scoreboard::Scoreboard(string name, string surname, string score)
{
	setName(name);
	setSurname(surname);
	setScore(score);
}

void Scoreboard::setName(string name) { this->name = name; }
void Scoreboard::setSurname(string surname) { this->surname = surname; }
void Scoreboard::setScore(string score) { this->score = score; }

string Scoreboard::getName() { return name; }
string Scoreboard::getSurname() { return surname; }
string Scoreboard::getScore() { return score; }


Scoreboard::~Scoreboard()
{
}
