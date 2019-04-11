#include "dietplan.h"

//getters
int DietPlan::getCalorie()
{
	return calorie;
}
string DietPlan::getName()
{
	return name;
}
string DietPlan::getDate()
{
	return date;
}
// setters
bool DietPlan::setCalorie(int temp_calorie)
{
	calorie = temp_calorie;
	return true;
}
bool DietPlan::setName(string temp_name)
{
	name = temp_name;
	return true;
}
bool DietPlan::setDate(string temp_date)
{
	date = temp_date;
	return true;
}

//////////////// constructor and deconstructor
DietPlan::DietPlan()
{
	calorie = 1000;
	name = "Paleo vegetarian Low-Carb Diet";
	date = "6/29/2007";
}

DietPlan::~DietPlan()
{
	cout << "Diet plan being deleted";
}
//////////////////
void DietPlan::editGoal()
{
	int data = 0;
	cout << "Enter a new Goal" << endl;
	cin >> data;							////////////This validation loop was taken from Stack Over flow  Query :Checking cin input stream produces an integer
	while (cin.fail())
	{
		cout << "You Did Not Enter A Number" << endl;
		cout << "Enter a new Goal" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> data;
		system("CLS");
	}//makes sure user is enter an int
	this->setCalorie(data);
}

//////////////// nonmenber
fstream& operator << (fstream &outfile, DietPlan &plan)
{
	outfile << plan.getName() << endl
		<< plan.getCalorie() << endl
		<< plan.getDate() << endl;
	return outfile;
}
ostream& operator << (ostream &print, DietPlan &plan)
{
	cout << plan.getName() << endl
		<< plan.getCalorie() << endl
		<< plan.getDate() << endl;
	return print;
}
fstream& operator >> (fstream &infile, DietPlan &plan)
{
	string name;
	int calorie;
	getline(infile, name);//set name
	if (name == "")getline(infile, name);// makes sure not reaing blank line
	plan.setName(name);

	getline(infile, name); //sets calorie
	if (name == "")getline(infile, name);// makes sure not reaing blank line
	calorie = stoi(name);
	plan.setCalorie(calorie);

	getline(infile, name); // sets date
	if (name == "")getline(infile, name);// makes sure not reaing blank line
	plan.setDate(name);
	return infile;
}