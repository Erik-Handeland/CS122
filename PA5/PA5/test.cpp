#include "Test.h"


test::test()
{

	Queue *testQueueOneEn = new Queue;

	Queue *testQueueOneDe = new Queue;

	Queue *testQueueTwo = new Queue;

	Queue *testQueueEmpty = new Queue;
}

test::~test()
{

}

bool test::emptyEn()
{
	Data *Temp = new Data;
	testQueueEmpty.enqueue(*Temp);
	if (testQueueEmpty.isEmpty())
	{
		return false;
	}
	return true;
}

bool test::oneEn()
{
	Data *Temp = new Data;
	testQueueOneEn.enqueue(*Temp);

	Data *Tempb = new Data;
	testQueueEmpty.enqueue(*Tempb);

	testQueueOneEn.dequeue();
	if (testQueueEmpty.isEmpty())
	{
		return false;
	}
	return true;
}
bool test::oneDe()
{
	Data *Temp = new Data;
	testQueueOneDe.enqueue(*Temp);

	testQueueOneDe.dequeue();
	if (testQueueEmpty.isEmpty())
	{
		return true;
	}
	return true;
}
bool test::twoDe()
{
	Data *Temp = new Data;
	testQueueTwo.enqueue(*Temp);

	Data *Tempb = new Data;
	testQueueTwo.enqueue(*Tempb);

	testQueueTwo.dequeue();
	testQueueTwo.dequeue();
	if (testQueueTwo.isEmpty())
	{
		return true;
	}
	return false;
}
