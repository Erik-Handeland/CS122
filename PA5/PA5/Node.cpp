#include "Node.h"
#include "Header.h"


Node::Node()
{
	pData = nullptr;
	pNext = nullptr;
}
Node::Node(Data &data)
{
	pData = new Data;
	this->pData = new Data(data);
	this->pNext = nullptr;
}
Node::Node( Node &data) {
	pData = new Data;
	this->pData = data.pData;
	this->pNext = data.pNext;
}
Node::~Node()
{
}

void Node::setNextPointer(Node *newnode)
{
	this->pNext = newnode;
}
void Node::setdata(Data &newdata)
{
	this->pData = &newdata;
}

Data *Node::getdata()
{
	return this->pData;
}
Node *Node::getNextPointer()
{
	return this->pNext;
}