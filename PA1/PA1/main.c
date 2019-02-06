/*******************************************************************************************
* Programmer: Erik Handeland                                                                 *
* Class: CptS 122, Spring, 2019; Lab Section 6                                          *
* Programming Assignment: #1 Fitbit Data                                                     *
* Date: January 23, 2019                                                                          *
* Description: This program reads fitbit data in the form of a cvs file and outputs stats.      *
*******************************************************************************************/

#include "Header.h"

int main()
{
	//////////////////////////////////// File Reading
	FitbitData userDataArray[1442] = { '\0' }; // struct of type fitbitdata used to store 24 hours worth of data
	FitbitData *ptr_userData;
	ptr_userData = &userDataArray;
	
	////////////////////////////////// Computed data struct
	computed_Data User_Data_Results[1] = {0};
	computed_Data *ptr_Data_results;
	ptr_Data_results = User_Data_Results;
	
	char unparsedPatientData[1500][100] = { { '\0' } }; // stores one line of data from csv file

	//Opens data file for reading
	FILE *infile = NULL, *outfile = NULL;
	infile = fopen("FitbitData.csv", "r");
	outfile = fopen("Results.csv", "w+");

	if (infile != NULL) //File Opened
	{
		printf("Data File Opened");
		cont_promt(); //continue promt
		clear();  //clears screen
	}

	dataRetrieval(infile, unparsedPatientData); // retrives/stores data in 2d array
	parseData(unparsedPatientData, ptr_userData); // parsed data abd stores it into struct
	computeData(ptr_userData, ptr_Data_results); // computes data and stores into struct
	printData(ptr_userData, ptr_Data_results, outfile); // prints data

	fclose(infile);
	fclose(outfile);
	cont_promt();

}
