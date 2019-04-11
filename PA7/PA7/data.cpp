#include "data.h"
#include "Header.h"

string data::getID()
{
	return ID;
}

string data::getName()
{
	return Name;
}
string data::getEmail()
{
	return Email;
}
string data::getUnits()
{
	return Units;
}
string data::getProgram()
{
	return Program;
}
string data::getLevel()
{
	return Level;
}

void data::setID(string id)
{
	ID = id;
}
void data::setName(string name)
{
	Name = name;
}
void data::setEmail(string email)
{
	Email = email;
}
void data::setUnits(string units)
{
	Units = units;
}
void data::setProgram(string p)
{
	Program = p;
}
void data::setLevel(string l)
{
	Level = l;
}

data::data()
{
	ID = "0";
	Name = "Ace";
	Email = "Ace@wsu.edu";
	Units = "0";
	Program = "CS";
	Level = "Wizard";
}

data::~data()
{
}