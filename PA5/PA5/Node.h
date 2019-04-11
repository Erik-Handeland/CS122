#pragma once
#include "Data.h"
class Node
{

public: // Member functions
	Node();
	Node(Data &data);
	Node(Node &data);
	~Node();

	void setNextPointer(Node *newnode);
	void setdata(Data &newdata);

	Data *getdata();
	Node *getNextPointer();

private:
	Data *pData;    // The memory for Data will need to be allocated on the heap as well!
	Node *pNext;
};
