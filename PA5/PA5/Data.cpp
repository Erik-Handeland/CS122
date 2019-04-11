#include "Data.h"
#include "Header.h"

//Setter
void Data::setID(int id)
{
	customerID = id;
}

void Data::setTime(int time)
{
	serviceTime = time;
}
void Data::setTotalTime(int time)
{
	totalTime = time;
}

//Getter
int Data::getID() 
{
	return customerID;
}
int Data::getTime()
{
	return serviceTime;
}
int Data::GetTotalTime()
{
	return totalTime;
}

//Constructor/Deconstructor
Data::Data()
{
	customerID = 1;
	serviceTime = 2;
	totalTime = 3;
}
Data::~Data()
{
}

Data::Data(Data &copy) {
	customerID = copy.getID();
	serviceTime = copy.getTime();
	totalTime = copy.GetTotalTime();
}

Data::Data(int id, int service, int elapsed) {
	customerID = id;
	serviceTime = service;
	totalTime = serviceTime + elapsed;
}

Data::Data(int id, int service) {
	customerID = id;
	serviceTime = service;
	totalTime = 0;
}