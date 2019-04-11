#pragma once
#include "Header.h"

class stack
{
public:
	stack();
	~stack();
	void push(string d);
	string pop();
	string peek();
	string peek(int day);
	bool isEmpty();

	int getAbsences();
	void setAbsences(int i);
	void setDay(int i, string newdata);

private:
	int absences;
	string days[100];

};
