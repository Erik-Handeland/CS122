#include "list.h"
#include "Header.h"

 template<typename T>
 list<T>* list<T>::getHead()
 {
	 return pHead;
 }
 template <typename T>
bool list<T>::isEmpty()
{
	if (pHead == nullptr)
	{
		return true;
	}
	return false;
}

template <typename T>
void list<T>::setHead(T *newData)
{
	pHead = newData;
}

template <typename T>
void list<T>::insertFront(T *newData)
{
	if (this->isEmpty())
	{
		pHead = newData;
	}
	else
	{
		newData->setNext(pHead);
		this->setHead(newData);
	}
}

template <typename T>
list<T>::list()
{
	pHead = nullptr;
}

template <typename T>
list<T>::~list()
{
}