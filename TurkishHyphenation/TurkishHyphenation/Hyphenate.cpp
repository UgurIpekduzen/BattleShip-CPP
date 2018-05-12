#include "Hyphenate.h"



Hyphenate::Hyphenate()
{
	setASCIIprintables();
	readTextFile();
}

void Hyphenate::setASCIIprintables()
{
	ASCIIprintables.push_back('\n');
	for (int i = 32; i < 64; i++)
		ASCIIprintables.push_back(static_cast<char>(i));
}

void Hyphenate::readTextFile()
{
	string sentence;
	ifstream textFile;
	textFile.open("denizli.txt");

	while (!textFile.eof()) {
		getline(textFile, sentence, '.');
		text.push_back(sentence);
	}
}

Hyphenate::~Hyphenate()
{
}
