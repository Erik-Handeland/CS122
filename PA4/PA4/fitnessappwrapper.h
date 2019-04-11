#pragma once
#include "Header.h"
#include "exerciseplan.h"
#include "dietplan.h"

class FitnessAppWrapper
{
	string user = "test";

public:
	void runApp();
	FitnessAppWrapper();
	~FitnessAppWrapper();
	//Loaders
	void loadDailyExericePlan(fstream &infile, ExercisePlan &ExerciseArray);
	void loadDailyDietPlan(fstream & infile, DietPlan &dietArray);
	void loadWeeklyExericePlan(fstream &infile, ExercisePlan exericeArray[]);
	void loadWeeklyDietPlan(fstream &infile, DietPlan dietArray[]);
	//Displayers
	void displayDailyExcericePlan(ExercisePlan &plan);
	void displayDailyDietPlan(DietPlan &plan);
	void displayWeeklyExcericePlan(ExercisePlan exericeArray[]);
	void displayWeeklyDietPlan(DietPlan dietArray[]);
	//Storers
	void storeDailyExericePlan(fstream &outfile, ExercisePlan &plan);
	void storeDailyDietPlan(fstream &outfile, DietPlan &plan);
	void storeWeeklyExericePlan(fstream &outfile, ExercisePlan exericeArray[]);
	void storeWeeklyDietPlan(fstream &outfile, DietPlan dietArray[]);
	//Menu
	int FitnessAppWrapper::menu();
};
