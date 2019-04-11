#pragma once
#include "Node.h"

class Queue

{
public: // Member functions
	Queue();
	~Queue();

	void enqueue(Data &data);
	Data dequeue();

	void printQueue();

	bool isEmpty(); // return true or false

	int getTotalTime();


private:

	Node *pHead;
	Node *pTail;
};

