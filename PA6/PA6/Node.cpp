#include "Node.h"


Node::Node()
{
	Character = '\0';
	Code = "\0";
	mpLeft = nullptr;
	mpRight = nullptr;
}
Node::Node(char *newData, string *newdata)
{
	Character = *newData;
	Code = *newdata;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node()
{

}

string Node::getCode()
{
	return Code;
}

char Node::getChar()
{
	return Character;
}
Node * Node::getLeftPtr()
{
	return mpLeft;
}
Node * Node::getRightPtr()
{
	return mpRight;
}

void Node::setCode(string newData)
{
	Code = newData;
}

void Node::setChar(char newdata)
{
	Character = newdata;
}
void Node::setLeftPtr(Node *pNewLeft)
{
	mpLeft = pNewLeft;
}
void Node::setRightPtr(Node *pNewRight)
{
	mpRight = pNewRight;
}
