#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include<windows.h>
#include <mmsystem.h>
#pragma comment (lib, "winmm.lib")

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
void newNode(Node **pHead, Record Data);
void load(FILE *infile, Node **pHead, int *nodes);
int display(Node **pHead);
int printSearch(Node *temp, char search[MAX]);
int printAll(Node *pHead);
Record getData();
int edit(Node **pHead, char song[], char artist[], int rate);
void delay(int number_of_seconds); // geeksforgeek
Record searchNode(Node *pHead, char song[], char artist[]);
int play(Node *pHead);
int displayNode(Node *pHead);
int insert(Node **pHead, int test);
int deleteNode(Node **pHead, char song[]);
int shuffle(Node *pHead, int node_size);
int shuffle_array(int shuffle[MAX], int node_size);
int sort_menu(Node **pHead, int node_size);
int sort_artist(Node **pHead, int node_size);
int switchNodes(Node **a, Node **b, Record *data);
int sort_Album(Node **pHead, int node_size);
int sort_Rating(Node **pHead, int node_size);
int sort_PlayCount(Node **pHead, int node_size);
int play_song();

int clear_Screen();
int cont_promt();