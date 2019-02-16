#pragma once
#include "Common.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX 50

typedef struct duration
{
	int minutes;
	int seconds;
}Duration;

typedef struct record
{
	char artist[50];
	char album[50];
	char song[50]; 
	char genre[20];
	struct duration;
	int playCount;
	int Rating;
} Record;

typedef struct node
{
	Record data;
	struct node *pPrev;
	struct node *pNext;
} Node;

int menu(int *selection);
void dataRetrieval(FILE *infile, char unparsedData[50][100]);
void dataCorrection(char unparsedData[50][100]);
void newNode(Node **pHead, Record Data);
void load(char unparsedData[50][100], Node **pHead);
