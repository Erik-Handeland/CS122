#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1442 //max is the max number of lines that should be in the file
#define TRUE 1
#define FALSE 0

typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

typedef struct computedUserData
{
	double totalCalories;
	double totalDistance;
	double totalFloors;
	double totalSteps;
	double avgHeartrate;
	double minuteMaxSteps;
	int sleepRange[2]; //[0] is start of range [1] is end of range
} computed_Data;

void dataRetrieval(FILE *infile, char unparsedData[1500][100]);
void parseData(char unparsedData[1500][100], FitbitData *userDataArray);
void computeData(FitbitData *userDataArray, computed_Data *userData);
void printData(FitbitData *userDataArray, computed_Data *userData, FILE *outfile);
//void parse_line(char unparsedData[1500][100], int line, struct FitbitData userDataArray[1442]);



// Common Functions
int clear();
int cont_promt();