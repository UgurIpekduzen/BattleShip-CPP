#pragma once
class Letter
{
private:
	char letter;
	int count;
public:
	Letter();
	Letter(char letter, int count);
	void setLetter(char letter);
	void setCount(int count);
	char getLetter();
	int getCount();
	~Letter();
};

