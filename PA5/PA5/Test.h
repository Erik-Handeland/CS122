#include "Header.h"
#include "Queue.h"

class test
{
public:
	test();
	~test();
	bool emptyEn();
	bool oneEn();
	bool oneDe();
	bool twoDe();

private:
	Queue testQueueOneEn;
	Queue testQueueOneDe;
	Queue testQueueTwo;
	Queue testQueueEmpty;

};
