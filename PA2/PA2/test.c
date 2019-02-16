#include "Test.h";

int test_insert(Node **test)
{
	insert(test, 1);
}

int test_delete(Node **test)
{
	char song[50] = "Chained to the Rhythm";
	deleteNode(test, song);
}

int test_shuffle(Node **test)
{
	//take to much time to make
}
