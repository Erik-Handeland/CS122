#include "Header.h"
#include "Queue.h"
#include "Test.h"

//	Erik Handeland
//	PA 5
//	3/18/2019
//	Objective: Simulate a grocery store
//	Didn't finish: doesnt load multiple people into a line, and print doesnt work
//	due to only one person being in the line... they are dequeue before they can print




int main()
{
	srand(time(NULL));
	int selection = 0;
	cout << "Enter a number \n" 
		<< "1:  Run App \n"
		<< "2:  Run Test \n" 
		<<endl;
	cin >> selection;

	Queue normalLane; //queue creaters
	Queue expressLane;

	if (selection == 1)
	{
		int runtime = 0;
		system("CLS");
		cout << "Enter the runtime for the simulation" << endl;
		cin >> runtime;

		int normalArrival = 0;
		int expressArrival = 0;
		int totalTime = 0;
		
		expressArrival = rand() % 5 + 1;//seed data
		normalArrival = rand() % 6 + 3;

		Data *tempDataE = new Data; // data loader
		Data *tempDataN = new Data; // data loader

		for (int i = 0; i < runtime; i++)
		{
			//step 2
			if (normalArrival != 0)
			{
				normalArrival--;
			}
			else
			{
				cout << "A Customer has entered the Normal Lane" << endl << endl;
				tempDataN->setTime(rand() % 6 + 3);
				tempDataN->setTotalTime(i + tempDataN->getTime());
				normalLane.enqueue(*tempDataN);
				normalArrival = rand() % 6 + 3;
			}
			if (expressArrival != 0)
			{
				expressArrival--;
			}
			else
			{
				cout << "A Customer has entered the Express Lane" << endl << endl;
				tempDataE->setTime(rand() % 5 + 1);
				tempDataE->setTotalTime(i + tempDataE->getTime());
				expressLane.enqueue(*tempDataE);
				expressArrival = rand() % 5 + 1;
			}

			//step 3
			//express lane
			Data *printData = new Data;
			if (!expressLane.isEmpty() && i == expressLane.getTotalTime())
			{
				*printData = expressLane.dequeue();
				cout << "A Customer: " << printData->getID() << " has left the Express Lane at " << (printData->GetTotalTime()) << " minutes" << endl << endl;
			}
			//normal lane
			if (!normalLane.isEmpty() && i == normalLane.getTotalTime())
			{
				*printData = normalLane.dequeue();
				cout << "A Customer: " << printData->getID() << " has left the Normal Lane at " << (printData->GetTotalTime())<< " minutes" << endl << endl;
			}

			//step 4
		
			if (!(expressLane.isEmpty() && normalLane.isEmpty()) && ( i % 10 == 0 || i-10==0))
			{
				cout << i << " Minutes have passed, Current progress: " << endl;
				cout << "Express:" << endl;
				expressLane.printQueue();
				cout << "Normal:" << endl;
				normalLane.printQueue();
			}

		}
	}
	else if(selection == 2)
	{
		test testQueue;

		if (testQueue.emptyEn() == true)
		{
			cout << "Emptry Enqueue passed" << endl;
		}
		else
		{
			cout << "Emptry Enqueue failed" << endl;
		}
		if (testQueue.oneEn() == true)
		{
			cout << "One Enqueue passed" << endl;
		}
		else
		{
			cout << "one Enqueue failed" << endl;
		}

		if (testQueue.oneDe() == true)
		{
			cout << "one Dequeue passed" << endl;
		}
		else
		{
			cout << "one Dequeue failed" << endl;
		}

		if (testQueue.twoDe() == true)
		{
			cout << "Two Dequeue passed" << endl;
		}
		else
		{
			cout << "Two Dequeue failed" << endl;
		}

		system("pause");
		system("cls");

		int runtime = 1440;

		int normalArrival = 0;
		int expressArrival = 0;
		int totalTime = 0;

		expressArrival = rand() % 5 + 1;//seed data
		normalArrival = rand() % 6 + 3;

		Data *tempDataE = new Data; // data loader
		Data *tempDataN = new Data; // data loader

		for (int i = 0; i < runtime; i++)
		{
			//step 2
			if (normalArrival != 0)
			{
				normalArrival--;
			}
			else
			{
				cout << "A Customer has entered the Normal Lane" << endl << endl;
				tempDataN->setTime(rand() % 6 + 3);
				tempDataN->setTotalTime(i + tempDataN->getTime());
				normalLane.enqueue(*tempDataN);
				normalArrival = rand() % 6 + 3;
			}
			if (expressArrival != 0)
			{
				expressArrival--;
			}
			else
			{
				cout << "A Customer has entered the Express Lane" << endl << endl;
				tempDataE->setTime(rand() % 5 + 1);
				tempDataE->setTotalTime(i + tempDataE->getTime());
				expressLane.enqueue(*tempDataE);
				expressArrival = rand() % 5 + 1;
			}

			//step 3
			//express lane
			Data *printData = new Data;
			if (!expressLane.isEmpty() && i == expressLane.getTotalTime())
			{
				*printData = expressLane.dequeue();
				cout << "A Customer: " << printData->getID() << " has left the Express Lane at " << (printData->GetTotalTime()) << " minutes" << endl << endl;
			}
			//normal lane
			if (!normalLane.isEmpty() && i == normalLane.getTotalTime())
			{
				*printData = normalLane.dequeue();
				cout << "A Customer: " << printData->getID() << " has left the Normal Lane at " << (printData->GetTotalTime()) << " minutes" << endl << endl;
			}

			//step 4

			if (!(expressLane.isEmpty() && normalLane.isEmpty()) && (i % 10 == 0 || i - 10 == 0))
			{
				cout << i << " Minutes have passed, Current progress: " << endl;
				cout << "Express:" << endl;
				expressLane.printQueue();
				cout << "Normal:" << endl;
				normalLane.printQueue();
			}

		}

	}
	else
	{
		cout << "You did not enter a valid option... Application will close now" << endl;
		system("PAUSE");
		return 0;
	}
	system("PAUSE");
	return 0;
}
