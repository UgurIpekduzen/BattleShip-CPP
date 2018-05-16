#pragma once
#include"Word.h"
#include "Letter.h"
#include <vector>
#include <fstream>
#include <string>
#include<cstdlib>
#include<string.h>

enum vectors { LETTER = 1, WORD = 2, SYLLABLE = 3 };
class Hyphenate
{
private:
	vector<string> text;
	vector<Letter> letters;
	/*vector<Word> syllables;
	vector<Word> words;*/
	vector<char> ASCIIprintables;
	int letterIndex;
public:
	Hyphenate();
	void setASCIIprintables();
	void readTextFile();
	void hyphenateLetters();
	void printVectors();
	void hypenateSyllables();
	void hypenateWords();
	void sortHighestToLowest(int whichVec);
	bool isTheSameLetter(char ch);
	bool isASCIIprintable(char ch);
	//Ek metodlar
	bool isUpper(char ch);
	int toLower(char ch);
	~Hyphenate();
};

