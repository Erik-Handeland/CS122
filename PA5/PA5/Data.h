#pragma once
class Data
{
public: // Member functions
	Data();
	Data(Data &copy);
	Data(int id, int service);
	Data(int id, int service, int elapsed);
	~Data();

	void setID(int id);
	void setTime(int time);
	void setTotalTime(int time);
	int getID();
	int getTime();
	int GetTotalTime();


private:

	int customerID; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

}; // This memory needs to be allocated on the heap!

