#include "Hyphenate.h"
#pragma warning(disable:4996)


Hyphenate::Hyphenate()
{
	setASCIIprintables();
	readTextFile();
}

void Hyphenate::setASCIIprintables()
{
	ASCIIprintables.push_back('\n');
	
	for (int i = 32; i < 64; i++)
		if (i == 32 || i == 39) continue; // Daha sonraki metodlarda kurulacak mantýklarýn düzgün çalýþmasý için ' ' ve ',' karakterleri çýkartýlýr.
		else
		ASCIIprintables.push_back(static_cast<char>(i));
}

void Hyphenate::readTextFile()
{
	string sentence;
	ifstream textFile;
	textFile.open("denizli.txt");

	while (!textFile.eof()) {
		getline(textFile, sentence, '\n');

		for (int i = 0; i < sentence.length(); i++)
			if (isUpper(sentence[i]))
				sentence[i] = toLower(sentence[i]);

		text.push_back(sentence);
	}
}

void Hyphenate::hyphenateLetters()
{
	for (int i = 0; i < text.size(); i++) {
		
		for (int j = 0; j < text[i].length(); j++) {
			if (isASCIIprintable(text[i][j]) || text[i][j] == 32 || text[i][j] == 39) continue;
			else {
				if (isTheSameLetter(text[i][j]))
					letters[letterIndex].setCount(letters[letterIndex].getCount() + 1);
				else 
					letters.push_back(Letter((text[i][j]), 1));
			}
		}
	}
}

void Hyphenate::printVectors()
{
	sortHighestToLowest(LETTER);
	for (int i = 0;i < letters.size(); i++)
		cout << letters[i].getLetter() << ": " << letters[i].getCount() << endl;
	
	/*sortHighestToLowest(WORD);
	for (int i = 0;i < 10; i++)
		cout << words[i].getText() << ": " << words[i].getCount() << endl;*/
	
	/*sortHighestToLowest(SYLLABLE);
	for (int i = 0;i < 10; i++)
		cout << syllables[i].getText() << ": " << syllables[i].getCount() << endl;*/
}

void Hyphenate::hypenateSyllables()
{

}

void Hyphenate::hypenateWords()
{
	
}

void Hyphenate::sortHighestToLowest(int whichVec)
{
	Letter letterTemp;
	Word wordTemp, syllableTemp;
	switch (whichVec)
	{
	case LETTER:
		for (int i = 0; i < letters.size(); i++) {
			for (int j = 0; j < letters.size() - i - 1; j++) {
				if (letters[j + 1].getCount() > letters[j].getCount())
				{
					letterTemp = letters[j];
					letters[j] = letters[j + 1];
					letters[j + 1] = letterTemp;
				}
			}
		}
		break;
	/*case WORD:
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words.size() - i - 1; j++) {
				if (words[j + 1].getCount() > words[j].getCount())
				{
					wordTemp = words[j];
					words[j] = words[j + 1];
					words[j + 1] = wordTemp;
				}
			}
		}
		break;
	case SYLLABLE:
		for (int i = 0; i < syllables.size(); i++) {
			for (int j = 0; j < syllables.size() - i - 1; j++) {
				if (syllables[j + 1].getCount() > syllables[j].getCount())
				{
					syllableTemp = syllables[j];
					syllables[j] = syllables[j + 1];
					syllables[j + 1] = syllableTemp;
				}
			}
		}
		break;*/
	}
}


bool Hyphenate::isTheSameLetter(char ch)
{
	for (int i = 0; i < letters.size(); i++) {
		if (ch == letters[i].getLetter()) {
			letterIndex = i;
			return true;
		}
	}
	return false;
}

bool Hyphenate::isASCIIprintable(char ch)
{
	for (int i = 0; i < ASCIIprintables.size(); i++)
		if (ch == ASCIIprintables[i]) return true;
	return false;
}

bool Hyphenate::isUpper(char ch)
{
	for (int i = 65; i < 91; i++)
		if (ch == i) return true;
	return false;
}

int Hyphenate::toLower(char ch) { return ch + 32; }

Hyphenate::~Hyphenate()
{
}
