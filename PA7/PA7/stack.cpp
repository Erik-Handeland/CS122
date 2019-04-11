#include "stack.h"

void stack::push(string d)
{
	days[absences - 1] = d;
}

string stack::pop()
{
	string temp = peek();

	days[absences - 1] = "null";
	absences--;

	return temp;
}
string stack::peek()
{
	return days[absences -1];
}
string stack::peek(int day)
{
	return days[day];
}
bool stack::isEmpty()
{
	if (absences == 0& days[absences] == "null")
	{
		return true;
	}
	return false;
}

int stack::getAbsences()
{
	return absences;
}
void stack::setAbsences(int i)
{
	absences = i;
}
stack::stack()
{
	absences = 0;
	days[0] = "null";
}

stack::~stack()
{
}

void stack::setDay(int i, string newdata)
{
	if (this->isEmpty())
	{
		days[i] = newdata;
		absences++;
	}
	else
	{
		days[i] = newdata;

	}
}
