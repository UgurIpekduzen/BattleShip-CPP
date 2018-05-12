#pragma once
#include <iostream>
using namespace std;
class Word
{
private:
	string text;
	int count;
public:
	Word();
	Word(string text, int count);
	
	void setText(string text);
	void setCount(int count);

	string getText();
	int getCount();
	~Word();
};

