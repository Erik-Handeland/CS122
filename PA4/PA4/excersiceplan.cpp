#include "exerciseplan.h"

//getters
int ExercisePlan::getSteps()
{
	return steps;
}
string ExercisePlan::getName()
{
	return name;
}
string ExercisePlan::getDate()
{
	return date;
}
// setters
bool ExercisePlan::setSteps(int temp_steps)
{
	steps = temp_steps;
	return true;
}
bool ExercisePlan::setName(string temp_name)
{
	name = temp_name;
	return true;
}
bool ExercisePlan::setDate(string temp_date)
{
	date = temp_date;
	return true;
}

//////////////// constructor and deconstructor
ExercisePlan::ExercisePlan()
{
	steps = 1000;
	name = "Arnold Schwarzenegger's Super Duper Bowflex Pilates";
	date = "3/24/2001";
}

ExercisePlan::~ExercisePlan()
{
	cout << "Diet plan being deleted";
}
//////////////////
void ExercisePlan::editGoal()
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
	} //makes sure user is enter an int
	this->setSteps(data);

}


//////////////// nonmenber
fstream& operator << (fstream &outfile, ExercisePlan &plan)
{
	outfile << plan.getName() << endl
		<< plan.getSteps() << endl
		<< plan.getDate() << endl;
	return outfile;
}
ostream& operator << (ostream &print, ExercisePlan &plan)
{
	cout << plan.getName() << endl
		<< plan.getSteps() << endl
		<< plan.getDate() << endl;
	return print;
}
fstream& operator >> (fstream &infile, ExercisePlan &plan)
{
	string name;
	int steps;
	getline(infile, name);//set name
	if (name == "")getline(infile, name);// makes sure not reaing blank line
	plan.setName(name);

	getline(infile, name); //sets calorie
	if (name == "")getline(infile, name);// makes sure not reaing blank line
	steps = stoi(name);
	plan.setSteps(steps);

	getline(infile, name); // sets date
	if (name == "")getline(infile, name);// makes sure not reaing blank line
	plan.setDate(name);
	return infile;
}