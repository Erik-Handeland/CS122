#include "node.h"
#include "Header.h"

template <typename T>
data node<T>::getStudent()
{
	return Student;
}

template <typename T>
stack node<T>::getAttendence()
{
	return Attendence;
}

template <typename T>
T * node<T>::getNext()
{
	return pnext;
}

template <typename T>
void node<T>::setNext(T *newnode)
{
	pnext = newnode;
}

template <typename T>
void node<T>::setStudent(data newdata)
{
	Student = newdata;
}

template <typename T>
void node<T>::setAttendence(stack newdata)
{
	Attendence = newdata;
}

template <typename T>
node<T>::node()
{
	Student;
	Attendence;
	pnext = nullptr;
}

template <typename T>
node<T>::~node()
{
}