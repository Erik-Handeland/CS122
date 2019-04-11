#pragma once
#include "Header.h"

class Node
{
public:
	Node();
	Node(char *newData, string *newdata);
	~Node();

	string getCode();
	char getChar();
	Node *getLeftPtr();
	Node *getRightPtr();

	void setCode(string newData);
	void setChar(char newdata);
	void setLeftPtr(Node *pNewLeft);
	void setRightPtr(Node *pNewRight);

private:
	char Character;
	string Code;
	Node *mpLeft;
	Node *mpRight;
};