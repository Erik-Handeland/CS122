#include "fitnessappwrapper.h"

void FitnessAppWrapper::runApp()
{
	int selection = 0;
	int day = 0;

	bool loadedDiet = false;		//used to protect from not loading data
	bool loadedExercise = false;

	selection = menu();

	fstream dietFile, exerciseFile;
	dietFile.open("dietPlans.txt");
	exerciseFile.open("exercisePlans.txt");

	ExercisePlan *arrayExercise = new ExercisePlan[MAX];
	DietPlan *arrayDiet = new DietPlan[MAX];


	do
	{
		switch (selection)
		{
		case 1://Load weekly diet plan from file.
			if (loadedDiet == false)
			{
				loadWeeklyDietPlan(dietFile, arrayDiet);
				loadedDiet = true;
				cout << "Data Has been Loaded"<<endl;
			}
			else
			{
				cout << "Data was Already loaded" << endl;
			}
			system("PAUSE");
			system("CLS");
			selection = menu();
		
			break;
		case 2://Load weekly exercise plan from file.
			if (loadedExercise == false)
			{
				loadWeeklyExericePlan(exerciseFile, arrayExercise);
				cout << "Data Has been Loaded"<<endl;
				loadedExercise = true;
			}
			else
			{
				cout << "Data was Already Loaded" << endl;
			}
			system("PAUSE");
			system("CLS");
			selection = menu();
			break;
		case 3: //Store weekly diet plan to file.
			if (loadedDiet == true)
			{
				storeWeeklyDietPlan(dietFile, arrayDiet);
			}
			else
			{
				cout << "You havent loaded any data yet"<<endl;
				system("PAUSE");
				system("CLS");
			}
			selection = menu();
			break;
		case 4://Store weekly exercise plan to file.
			if (loadedExercise == true)
			{
				storeWeeklyExericePlan(exerciseFile, arrayExercise);
			}
			else
			{
				cout << "You havent loaded any data yet" << endl;
				system("PAUSE");
				system("CLS");
			}
			selection = menu();
			break;
		case 5://Display weekly diet plan to screen.
			if (loadedDiet == true)
			{
				displayWeeklyDietPlan(arrayDiet);
			}
			else
			{
				cout << "You havent loaded any data yet" << endl;
			}
			system("PAUSE");
			system("CLS");
			selection = menu();
			break;
		case 6://Display weekly exercise plan to screen.
			if (loadedExercise == true)
			{
				displayWeeklyExcericePlan(arrayExercise);
			}
			else
			{
				cout << "You havent loaded any data yet" << endl;
			}
			system("PAUSE");
			system("CLS");
			selection = menu();
			break;
		case 7://Edit daily diet plan.
			if (loadedDiet == true)
			{
				displayWeeklyDietPlan(arrayDiet);
				cout << "Enter a day to edit" << endl;
				cin >> day;
				system("PAUSE");
				system("CLS");
				arrayDiet[day - 1].editGoal();
				displayWeeklyDietPlan(arrayDiet);
				system("PAUSE");
				system("CLS");
			}
			else
			{
				cout << "You havent loaded any data yet" << endl;
				system("PAUSE");
				system("CLS");
			}
			selection = menu();
			break;
		case 8://Edit daily exercise plan.
			if (loadedExercise == true)
			{
				displayWeeklyExcericePlan(arrayExercise);
				cout << "Enter a day to edit" << endl;
				cin >> day;
				system("PAUSE");
				system("CLS");
				arrayExercise[day - 1].editGoal();
				displayWeeklyExcericePlan(arrayExercise);
				system("PAUSE");
				system("CLS");
			}
			else
			{
				cout << "You havent loaded any data yet" << endl;
				system("PAUSE");
				system("CLS");
			}
			selection = menu();
			break;
		case 9://Exit.   // Note: this must write the most recent weekly plans to the corresponding files.
			if (loadedExercise == true && loadedDiet == true)
			{
				storeWeeklyExericePlan(exerciseFile, arrayExercise);
				storeWeeklyDietPlan(dietFile, arrayDiet);
			}
			else
			{
				cout << "You havent loaded any data yet" << endl;
			}
			system("PAUSE");
			system("CLS");
			selection = 0;
			break;
		default:
			break;
		}

	} while (selection >= 1 && selection <= 9);
	return;
}

int FitnessAppWrapper::menu()
{
	int selection = 0;
		do
		{
		
			cout << "Please select an option\n\n"
				<< "(1)		Load weekly diet plan from file" << endl
				<< "(2)		Load weekly exercise plan from file" << endl
				<< "(3)		Store weekly diet plan to file" << endl
				<< "(4)		Store weekly exercise plan to file" << endl
				<< "(5)		Display weekly diet plan to screen" << endl
				<< "(6)		Display weekly exercise plan to screen." << endl
				<< "(7)		Edit daily diet plan." << endl
				<< "(8)		Edit daily exercise plan" << endl
				<< "(9)		Exit" << endl;

			scanf("%d", &selection);
			system("CLS");
		} while (selection < 1 || selection > 12);

		return selection;
}

//construct/destruct
FitnessAppWrapper::FitnessAppWrapper()
{
	return;
}

FitnessAppWrapper::~FitnessAppWrapper()
{
	return;
}

////Loaders
void FitnessAppWrapper::loadDailyExericePlan(fstream &infile, ExercisePlan &ExerciseArray)
{
	infile >> ExerciseArray;
}
void FitnessAppWrapper::loadDailyDietPlan(fstream &infile, DietPlan &dietArray)
{
	infile >> dietArray;
}
void FitnessAppWrapper::loadWeeklyExericePlan(fstream &infile, ExercisePlan ExerciseArray[])
{
	for (int i = 0; i < 7; i++)
	{
		loadDailyExericePlan(infile, ExerciseArray[i]);
	}
}
void FitnessAppWrapper::loadWeeklyDietPlan(fstream &infile, DietPlan DietArray[])
{
	for (int i = 0; i < 7; i++)
	{
		loadDailyDietPlan(infile, DietArray[i]);
	}
}

/////Displayers
void FitnessAppWrapper::displayDailyExcericePlan(ExercisePlan &plan)
{
	cout << plan << endl;
	return;
}
void FitnessAppWrapper::displayDailyDietPlan(DietPlan &plan)
{
	cout << plan << endl;
	return;
}
void FitnessAppWrapper::displayWeeklyExcericePlan(ExercisePlan exericeArray[])
{
	for (int i = 0; i < 7; i++)
	{
		cout << "######## Day:" << i + 1 << endl;
		displayDailyExcericePlan(exericeArray[i]);
	}
	return;
}
void FitnessAppWrapper::displayWeeklyDietPlan(DietPlan dietArray[])
{
	for (int i = 0; i < 7; i++)
	{
		cout << "######## Day:" << i + 1 << endl;
		displayDailyDietPlan(dietArray[i]);
	}
}
//Storers
void FitnessAppWrapper::storeDailyExericePlan(fstream &outfile, ExercisePlan &plan)
{
	outfile << plan;
	return;
}
void FitnessAppWrapper::storeDailyDietPlan(fstream &outfile, DietPlan &plan)
{
	outfile << plan;
	return;
}
void FitnessAppWrapper::storeWeeklyExericePlan(fstream &outfile, ExercisePlan exericeArray[])
{
	if (outfile.is_open()) //makes sure outfile is open for writing and not reading
	{
		outfile.close();
		outfile.open("exercisePlans.txt", fstream::out | std::fstream::trunc);
	}
	for (int i = 0; i < 7; i++)
	{
		storeDailyExericePlan(outfile, exericeArray[i]);
		outfile << endl;
	}
	if (outfile.is_open()) 
	{
		outfile.close();
	}	
	return;
}
void FitnessAppWrapper::storeWeeklyDietPlan(fstream &outfile, DietPlan dietArray[])
{
	if (outfile.is_open()) //makes sure outfile is open for writing and not reading
	{
		outfile.close();
		outfile.open("dietPlans.txt", fstream::out | std::fstream::trunc);
	}
	for (int i = 0; i < 7; i++)
	{
		storeDailyDietPlan(outfile, dietArray[i]);
		outfile << endl;
	}
	if (outfile.is_open())
	{
		outfile.close();
	}
	return;
}
