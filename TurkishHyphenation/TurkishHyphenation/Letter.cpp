#include "Letter.h"



Letter::Letter() { letter = count = 0; }

Letter::Letter(char letter, int count)
{
	setLetter(letter);
	setCount(count);
}

void Letter::setLetter(char letter) { this->letter = letter; }

void Letter::setCount(int count) { this->count = count; }

char Letter::getLetter() { return letter; }

int Letter::getCount() { return count; }


Letter::~Letter()
{
}
