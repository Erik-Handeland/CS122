

#include "Header.h"
#include "list.h"

void menu(int *selection)
{
	do
	{
		cout <<"Attendence Tracker \n\n"
			<< "1.    Import course list" << endl
			<< "2.    Load master list" << endl
			<< "3.    Store master list" << endl
			<< "4.    Mark absences" << endl
			<< "5.    BONUS: Edit absences" << endl
			<< "6.    Generate report" << endl
			<< "7.    Exit" << endl << endl;
		cin >> *selection;
		system("CLS");
	} while (*selection > 7 || *selection <1);
}

template <typename T>
void importCVS(T &attend, ifstream &infile)
{
	while (!infile.eof())
	{
		string readString;
		string firstName;
		node *temp_node = new node;
		data temp_data = temp_node->getStudent();

		//,ID,Name,Email,Units,Program,Level
		getline(infile, readString, ',');//trash

		getline(infile, readString, ',');
		temp_data.setID(readString);

		getline(infile, readString, ',');		//formats names so that it displays as first and last name combind
		readString = readString.replace(0, 1, " ");
		getline(infile, firstName, ',');
		firstName = firstName.substr(0, firstName.size() - 1);
		firstName += readString;
		temp_data.setName(firstName);

		getline(infile, readString, ',');
		temp_data.setEmail(readString);

		getline(infile, readString, ',');
		temp_data.setUnits(readString);

		getline(infile, readString, ',');
		temp_data.setProgram(readString);

		getline(infile, readString, ',');
		temp_data.setLevel(readString);
		if (infile.eof()) break; //my while loops have been causing issues could find out why so added the break
		temp_node->setStudent(temp_data);
		attend.insertFront(temp_node);
	}
}

template <typename T>
void exportList(T *temp_node, ofstream & outfile)
{
	data student = temp_node->getStudent();
	stack absent = temp_node->getAttendence();
	if (temp_node!=nullptr)
	{
		//,ID,Name,Email,Units,Program,Level
		outfile << "x," << student.getID() << ',' << student.getName() << ',' << student.getEmail() << ',' << student.getUnits()
			<< ',' << student.getProgram() << ',' << student.getLevel() << ',' << endl;
		outfile << absent.getAbsences() << ',';
		if (!absent.isEmpty())//dont know if I was supose to add it, but program prints out the attendence stack also
		{
			while (!absent.isEmpty() || absent.getAbsences() !=0)
			{
				outfile << absent.peek() << ',';
				absent.pop();
			}
		}
		else
		{
			outfile << "% no absent data" << ','; //if no data in stack 
		}
		if (temp_node->getNext() == nullptr)
		{
			return;
		}
		outfile << endl;
		exportList(temp_node->getNext(), outfile);
	}
	else
	{
		return;
	}
}

template <typename T>
void importTXT(T &attend, ifstream &infile)
{
	while (!infile.eof())
	{
		string readString;
		node *temp_node = new node;
		stack temp_stack = temp_node->getAttendence();
		data temp_data = temp_node->getStudent();

		//,ID,Name,Email,Units,Program,Level
		getline(infile, readString, ',');//trash
		if (readString.size() == 0)
		{
			break;
		}

		getline(infile, readString, ',');
		temp_data.setID(readString);

		getline(infile, readString, ',');
		temp_data.setName(readString);

		getline(infile, readString, ',');
		temp_data.setEmail(readString);

		getline(infile, readString, ',');
		temp_data.setUnits(readString);

		getline(infile, readString, ',');
		temp_data.setProgram(readString);

		getline(infile, readString, ',');
		temp_data.setLevel(readString);

	////////////////////////////////////////////// End reading student

		getline(infile, readString, ','); //read attendence
		temp_stack.setAbsences(stoi(readString));

		getline(infile, readString, ','); //read attendence
		if (readString[0] != '%')
		{
			temp_stack.push(readString);
		}
		////////////////////////////////////////// end read attendence
		temp_node->setStudent(temp_data);
		temp_node->setAttendence(temp_stack);
		attend.insertFront(temp_node);
	}
}

template <typename T>
void markAbsences(T *tempNode) //not editing data
{
	time_t t = time(0);   // get time now

	struct tm * now = localtime(&t);

	system("cls");
	string responce;
	data student = tempNode->getStudent();
	stack absent = tempNode->getAttendence();
	while (responce != "no"|| responce != "yes")
	{
		cout << "Mark " << student.getName() << " Absent for "<< (now->tm_year + 1900) << '-' << (now->tm_mon + 1) 
			<< '-' << now->tm_mday <<"?"<< endl << endl; //cout current date
		cout << "Yes || No ?" << endl;
		cin >> responce;
		for (int x = 0; x < responce.size() ; x++)
		{
			tolower(responce[x]); //converts test to lowercase
		}

		if (responce == "yes") break;//again while loops werent breaking on there own
		if (responce == "no") break;
	}
	if (responce == "yes") 
	{
		responce = std::to_string(now->tm_year + 1900);
		responce += '-';
		responce += std::to_string(now->tm_mon + 1);
		responce += '-';
		responce += std::to_string(now->tm_mday);
		absent.push(responce);
		tempNode->setAttendence(absent);
	}

	if (tempNode->getNext() == nullptr)return;
	markAbsences(tempNode->getNext());
	
}

//BONUS: Option 5 : Prompts for an ID number or name of student to edit.Prompts for the date of absence to edit.
template <typename T>
void editAbsences(T *temp_node, string id) //not editing data
{
	data student = temp_node->getStudent();
	stack absent = temp_node->getAttendence();
	string tempString;
	int day = 0;
	if (student.getID() == id)
	{
		int temp = absent.getAbsences();
		system("cls");
		while (!absent.isEmpty() || temp != 0)
		{
			cout <<day<<": "<< absent.peek() << '\t';
			temp--;
			if (temp == 0)break;
		}
		if (!absent.isEmpty())
		{
			cout << endl << "Enter a number to edit" << endl;
			cin >> day;
		}
		else
		{
			cout << endl << "List is empty" << endl;
		}
		cout << "Enter a new date" << endl;
		cin >> tempString;
		absent.setDay(day, tempString);
		temp_node->setAttendence(absent);
		return;
	}
	if (temp_node->getNext() == nullptr && student.getID() != id)
	{
		cout << "Student: " << id << " not found" << endl << endl;
		return;
	}
	else
	{
		editAbsences(temp_node->getNext(), id);
	}
}

template <typename T>
void printAbsences(T *temp_node)
{
	data student = temp_node->getStudent();
	stack absent = temp_node->getAttendence();
	if (temp_node != nullptr)
	{
		//,ID,Name,Email,Units,Program,Level
		cout << student.getID() << '\t' << student.getName() << endl;
		if (!absent.isEmpty())
		{
			cout << absent.peek() << endl<<endl;
		}
		else
		{
			cout << "no absentces" << endl << endl;
		}
		if (temp_node->getNext() == nullptr)
		{
			return;
		}
		printAbsences(temp_node->getNext());
	}
	else
	{
		return;
	}
}

template <typename T>
void printAbsences(T *temp_node, int number)
{
	data student = temp_node->getStudent();
	stack absent = temp_node->getAttendence();
	if (temp_node != nullptr)
	{
		if (number == absent.getAbsences())
		{
			//,ID,Name,Email,Units,Program,Level
			cout << student.getID() << '\t' << student.getName() << endl;
			if (!absent.isEmpty())
			{
				cout << absent.peek() << endl << endl;
			}
			else
			{
				cout << "no absentces" << endl << endl;
			}
		}
		if (temp_node->getNext() == nullptr)
		{
			return;
		}
		printAbsences(temp_node->getNext());
	}
	else
	{
		return;
	}
}