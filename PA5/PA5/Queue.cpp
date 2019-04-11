#include "Queue.h"
#include "Header.h"


Queue::Queue()
{
	this->pHead = nullptr;
	this->pTail = nullptr;
}

Queue::~Queue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

Data Queue::dequeue()
{
	Node *temp = new Node;
	Data *dataT = new Data;

	if (this->pTail == this->pHead)
	{
		// we have one node
		temp = this->pHead;
		this->pHead = this->pTail = nullptr;
		dataT = temp->getdata();
		delete temp;
	}
	else
	{
		// more than 1 node in queue
		temp = this->pHead;
		this->pHead = this->pHead->getNextPointer();
		dataT = temp->getdata();
		delete temp;
	}
	return *dataT;
}
void Queue::printQueue()
{
	int i = 1;
	Data *temp = new Data;
	Node *tNode = this->pHead;

	if (this->isEmpty())
	{
		cout << "Queue is Empty" << endl;
		return;
	}
	while (tNode->getdata() != nullptr|| temp != nullptr)
	{
		temp = tNode->getdata();
		cout << "Customer: " << i << endl
			<< "Service Time: " << temp->getTime() << endl
			<< "Total Time: " << temp->GetTotalTime() << endl << endl;
		i++;
		tNode = tNode->getNextPointer();
		if (tNode == NULL || tNode == nullptr)break;
	}
}

void Queue::enqueue(Data &data) //work on more
{
	Node *newNode = new Node(data);
	if (newNode != nullptr)
	{
		if (this->pHead == nullptr)
		{
			this->pHead = newNode;
		}
		else
		{
			this->pTail->setNextPointer(newNode);
		}
		this->pTail = newNode;
	}
}

bool Queue::isEmpty()
{
	if (this->pHead == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Queue::getTotalTime()
{
	Data *tempData = new Data;
	tempData = pHead->getdata();
	return tempData->GetTotalTime();
}