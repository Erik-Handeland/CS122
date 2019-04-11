#pragma once
#include "Header.h"

class FitnessAppWrapper
{
public:
	FitnessAppWrapper();
	~FitnessAppWrapper();
	//read plans
	int FitnessAppWrapper::readExerice(fstream myfile, ExericePlan ExericeArray[MAX]);
	//write plan
	int FitnessAppWrapper::writeExerice(fstream myfile, ExericePlan ExericeArray[MAX]);

private:
	

};

FitnessAppWrapper::FitnessAppWrapper()
{
}

FitnessAppWrapper::~FitnessAppWrapper()
{
}

int ExericePlan::readExerice(fstream myfile, ExericePlan ExericeArray[MAX])
{
	int x = 0;
	while (!myfile.eof())
	{
		myfile >> ExericeArray[x].name;
		myfile >> ExericeArray[x].steps;
		myfile >> ExericeArray[x].date;
		x++;
	}
}