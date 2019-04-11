#pragma once
#include "Header.h"

class DietPlan
{
public:
	DietPlan();
	~DietPlan();
	//setters
	bool setCalorie(int temp_calorie);
	bool setName(string temp_name);
	bool setDate(string temp_date);
	//getters
	int getCalorie();
	string getName();
	string getDate();

	void editGoal();
	
private:
	int calorie;
	string name;
	string date;
};
fstream& operator << (fstream &outfile, DietPlan &plan);
ostream& operator << (ostream &print, DietPlan &plan);
fstream& operator >> (fstream &infile, DietPlan &plan);
