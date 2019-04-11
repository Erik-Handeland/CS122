#pragma once
#include "node.h"

template <typename T>
class list
{
public:
	list();
	~list();

	list<T> *getHead();
	bool isEmpty();

	void setHead(T *newData);
	void insertFront(T *newData);

private:
	list<T> *pHead;

};

template <typename T>
void importCVS(T &attend, ifstream &infile);

template <typename T>
void importTXT(T &attend, ifstream &infile);

template <typename T>
void exportList(T *tempNode, ofstream &outfile);

template <typename T>
void markAbsences(T *tempNode);

template <typename T>
void printAbsences(T *temp_node);

template <typename T>
void printAbsences(T *temp_node, int number);

template <typename T>
void editAbsences(T *temp_node, string id);