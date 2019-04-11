#pragma once
#include "Header.h"


class data
{
public:
	data();
	~data();
	string getID();
	string getName();
	string getEmail();
	string getUnits();
	string getProgram();
	string getLevel();

	void setID(string id);
	void setName(string name);
	void setEmail(string email);
	void setUnits(string units);
	void setProgram(string p);
	void setLevel(string l);

private:
	// ID, Name, Email, Units, Program, Level
	string ID;
	string Name;
	string Email;
	string Units;
	string Program;
	string Level;
};