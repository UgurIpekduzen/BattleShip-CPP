#include "Word.h"



Word::Word()
{
	text = "";
	count = 0;
}

Word::Word(string text, int count)
{
	setText(text);
	setCount(count);
}

void Word::setText(string text) { this->text = text; }

void Word::setCount(int count) { this->count = count; }

string Word::getText() { return text; }

int Word::getCount() { return count; }


Word::~Word()
{
}
