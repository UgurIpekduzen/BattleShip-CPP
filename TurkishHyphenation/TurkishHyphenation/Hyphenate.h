#pragma once
#include"Word.h"
#include "Letter.h"
#include <vector>
#include <fstream>
#include<string>
class Hyphenate
{
private:
	vector<string> text;
	vector<Letter> letters;
	vector<Word> syllables;
	vector<Word> words;
	vector<char> ASCIIprintables;
public:
	Hyphenate();
	void setASCIIprintables();
	void readTextFile();
	~Hyphenate();
};

