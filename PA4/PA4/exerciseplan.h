#pragma once
#include "Header.h"
 
class ExercisePlan
{
private:
	int steps;
	string name;
	string date;
public:
	ExercisePlan();
	~ExercisePlan();
	//setters
	bool setSteps(int temp_steps);
	bool setName(string temp_name);
	bool setDate(string temp_date);
	//getters
	int getSteps();
	string getName();
	string getDate();

	void editGoal();
};

fstream& operator << (fstream &outfile, ExercisePlan &plan);
ostream& operator << (ostream &print, ExercisePlan &plan);
fstream& operator >> (fstream &infile, ExercisePlan &plan);