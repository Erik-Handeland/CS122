#pragma once
#include "Header.h"
#include "data.h"
#include "stack.h"

template <typename  T>
class node
{
public:
	node();
	~node();
	
	data getStudent();
	stack getAttendence();
	T *getNext();

	void setNext(T *newnode);
	void setStudent(data newdata);
	void setAttendence(stack newdata);


private:
	data Student;
	stack Attendence;
	T *pnext;
};
