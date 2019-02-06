#include "Header.h"

void dataRetrieval(FILE *infile, char unparsedData[1500][100])
{
	char userID[5] = "12cx7"; //User Target ID

	int line = 0;  //used for line number of 2d data arrau
	char temp[100]= "string" ; //temp string used to look up user id 
	while (!feof(infile))
	{
		int ID_check = FALSE;
		fgets(temp, 100,infile);

		
		if (temp[0] == userID[0] && temp[1] == userID[1]  //probably no the most elegant way 
			&& temp[2] == userID[2] && temp[3] == userID[3]// but if statment compared user id
			&& temp[4] == userID[4])						// to the temp string ID
		{
			ID_check = TRUE;		//ID matches
		}
		

		if (ID_check == TRUE)	//if ID is true temp data is copied to 2d data array ortherwise data is skipped
		{
			strcpy(unparsedData[line], temp);
			line++;
		}
		
	}


	for (int x = 0; x < MAX; x++) // finds empty fields and moves every item up one
	{
		for (int y = 0; y < 100; y++)
		{
			int org = y+1; // store where first original doumplicate was located
			if (unparsedData[x][y] == ',' && unparsedData[x][y+1] == ',')
			{
				for (int z = 98; z > y; z--)
				{
					unparsedData[x][z+1] = unparsedData[x][z];
				}
				unparsedData[x][org] = '%'; //chages empty field to % key which can be used later to find invalid inputs
				break;

			}
		}
	}
}

void parseData(char unparsedData[1500][100], FitbitData *userDataArray)
{
	//Patient, minute, calories, distance, floors, heart, steps, sleep_level
	 
	//parses the dada for each line
	for (int i = 0; i < MAX; i++)
	{
		strcpy(userDataArray[i].patient, strtok(unparsedData[i], ","));
		strcpy(userDataArray[i].minute, strtok(NULL, ","));
		userDataArray[i].calories = atof(strtok(NULL, ","));
		userDataArray[i].distance = atof(strtok(NULL, ","));
		userDataArray[i].floors = atoi(strtok(NULL, ","));
		userDataArray[i].heartRate = atoi(strtok(NULL, ","));
		userDataArray[i].steps = atoi(strtok(NULL, ","));
		userDataArray[i].sleepLevel = atoi(strtok(NULL, ","));

	}
}

void computeData(FitbitData *userDataArray, computed_Data *userData)
{
	int heartTotal = 0, heartReads = 0;
	for (int i = 0; i < MAX; i++)
	{

		//Totals
		userData[0].totalCalories += userDataArray[i].calories;
		userData[0].totalDistance += userDataArray[i].distance;
		userData[0].totalFloors += userDataArray[i].floors;
		userData[0].totalSteps += userDataArray[i].steps;

		//Heart Rate
		if (userDataArray[i].heartRate > 0)
		{
			heartTotal += userDataArray[i].heartRate;
			heartReads++;
		}

		//max minute
		if (userDataArray[i].steps > userData[0].minuteMaxSteps)
		{
			userData[0].minuteMaxSteps = userDataArray[i].steps;
		}

		//sleep
		int temp_start = 0, temp_end = 0, temp_sum = 0, sum = 0;
		int index = 0; // index for second function
		if (userDataArray[i].sleepLevel > 1)
		{
			temp_start = i; //start point of being awake
			index = i;
			for (; userDataArray[index].sleepLevel > 1;) //index from awake point until nolonger awake
			{
				++index;
				temp_end = index; // sets endpoint of range
				temp_sum += userDataArray[index].sleepLevel + userDataArray[i].sleepLevel; // sums up total sleep
			}

			if (temp_sum > sum) // temp sum greater max, set range
			{
				sum = temp_sum;
				userData[0].sleepRange[0] = temp_start;
				userData[0].sleepRange[1] = temp_end;
			}
		}

	}

	userData[0].avgHeartrate = heartTotal / heartReads; //calcs avg heart rate;
}
void printData(FitbitData *userDataArray, computed_Data *userData, FILE *outfile)
{
	printf("Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");
	fprintf(outfile, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");

	printf("%lf, %lf, %lf, %lf, %lf, %lf, %s : %s\n", userData[0].totalCalories, userData[0].totalDistance, 
		userData[0].totalFloors, userData[0].totalSteps, userData[0].avgHeartrate, userData[0].minuteMaxSteps,
		userDataArray[userData[0].sleepRange[0]].minute, userDataArray[userData[0].sleepRange[1]].minute);
	
	fprintf(outfile,"%lf, %lf, %lf, %lf, %lf, %lf, %s : %s\n", userData[0].totalCalories, userData[0].totalDistance,
		userData[0].totalFloors, userData[0].totalSteps, userData[0].avgHeartrate, userData[0].minuteMaxSteps,
		userDataArray[userData[0].sleepRange[0]].minute, userDataArray[userData[0].sleepRange[1]].minute);

}


/* First attempt at parsing data before

void parseData(char unparsedData[1500][100], struct FitbitData userDataArray[1442])
{
	int index = 0;
	for (int i = 0; i < MAX; i++) // goes through each line of data and parses
	{
		parse_line(unparsedData, i, userDataArray);
	}
	
}

void parse_line(char unparsedData[1500][100], int line, struct FitbitData userDataArray[1442])
{ 
	char temp[20] = { '\0' };
	char *local; //stores address of char location
	int x = 0; //stores location of address in realstion to array
	local = strchr(unparsedData[line], ','); // sets local to address of first ','
	while (local != NULL)
	{

		// *NOTE* (line * 100) is used to subtract the size of the 2d array as it iterates through
		x = local - unparsedData - (line * 100); //sets x to address of first ',' sub by first address
		if (unparsedData[line][x] == ',')
		{
			unparsedData[line][x] = '\0'; // sets ',' location to null char
		}
		local = strchr(local+1, ','); // moves localation postion to past the first ',' location
		//Patient, minute, calories, distance, floors, heart, steps, sleep_level
	}




}
*/

// Common Functions
int clear()
{
	system("cls"); // Clears Screen
}

int cont_promt()
{
	printf("\n Press Enter to continue \n");
	getchar();
} //simple promt