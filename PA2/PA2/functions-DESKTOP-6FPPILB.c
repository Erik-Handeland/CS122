#include "Header.h"


int menu(int *selection)
{
	do
	{
		printf("Please select an option\n\n");

		printf("(1)   \tload\n");
		printf("(2)   \tstore\n");
		printf("(3)   \tdisplay\n");
		printf("(4)   \tinsert\n");
		printf("(5)   \tdelete\n");
		printf("(6)   \tedit\n");
		printf("(7)   \tsort\n");
		printf("(8)   \trate\n");
		printf("(9)   \tplay\n");
		printf("(10) \tshuffle\n");
		printf("(11) \texit\n\n");

		scanf("%d", &selection);
		clear();
	} while (selection < 1 || selection > 12);

}

void dataRetrieval(FILE *infile, char unparsedData[50][100]) // gets song data from csv file and stores it into an array to be parsed later
{
	int line = 0;  //used for line number of 2d data arrau
	int i = 0;

	while (!feof(infile))
	{
		fgets(unparsedData[i], 100, infile);
	
		i++;
	}
}

void dataCorrection(char unparsedData[50][100]) //corrects datafields to work better with strtok: removes , in "" lines and fixes order of names
{
	for (int x = 0; x < MAX; x++) //find " in first lines
	{
		int a = 1;
		int b = 0;
		char temp_first[100] = "hello";
		char temp_last[100] = "hello";
		if (unparsedData[x][0] == '\"') // locateds "" line
		{
			unparsedData[x][0] == " ";
			temp_last[a -1] = ' '; // sets space for when first and last are combined
			while (unparsedData[x][a] != ',')
			{
				temp_last[a] = unparsedData[x][a]; //sets temp values for last name
				a++;
			}
			a++;
			while (unparsedData[x][a+1] != '\"') //sets temp values for first name
			{
				temp_first[b] = unparsedData[x][a +1];
				b++;
				a++;
			}

			strcat(temp_first, temp_last); //conjoins first and last name strings

			for (int t = 0; t < strlen(temp_first) ; t++)
			{
				if (t < strlen(temp_first))
				{
					unparsedData[x][t] = temp_first[t];
				}
			}
			for (int t = strlen(temp_first); unparsedData[x][t] != ','; t++) // since we are removing extra char, we replace the extra char with space 
			{																//  until it reaches the first ,
				unparsedData[x][t] = ' ';
			}
			
		}
	}
}

void newNode(Node **pHead, Record Data) // Help from O'Fallon Starter code
{
	Node *pNew = NULL;

	pNew = (Node *)malloc(sizeof(Node));
	if (pNew != NULL)
	{
		pNew->pNext = *pHead;

		if (!isEmpty(*pHead))
		{
			pNew->data = Data;
			(*pHead)->pPrev = pNew;
		}
		*pHead = pNew;
	}
}

void load(char unparsedData[50][100], Node **pHead)
{
	Node temp;
	Record data;
	int index = 0;
	char time[10] = { '\0' };
	while(unparsedData[index][0] != '\0')
	{
		
		strcpy(data.artist, strtok(unparsedData[index], ","));
		strcpy(data.album, strtok(NULL, ","));
		strcpy(data.song, strtok(NULL, ","));
		strcpy(data.genre, strtok(NULL, ","));
		strcpy(time, strtok(NULL, ","));
		data.playCount = atoi(strtok(NULL, ","));
		data.Rating = atoi(strtok(NULL, ","));
		data.minutes = atoi(strtok(time, ":"));
		data.seconds = atoi(strtok(NULL, ":"));
		
		newNode(&*pHead, data);

		index++;
	}
}

int isEmpty(Node *pList) // Taken from O'Fallon Starter code
{
	return (pList == NULL);
}



/*

Ø  What must “store” do?

The “store” command writes the current records, in the dynamic doubly linked list, to the musicPlayList.csv file. The store will completely overwrite the previous contents in the file.



Ø  What must “display” do?

The “display” command prints records to the screen. This command must support two methods, one of which is selected by the user:

1.    Print all records.

2.    Print all records that match an artist.



Ø  What must “edit” do?

The “edit” command must allow the user to find a record in the list by artist. If there are multiple records with the same artist, then your program must prompt the user which one to edit. The user may modify all of the attributes in the record.



Ø  What must “rate” do?

The “rate” command must allow the user to assign a value of 1 – 5 to a song; 1 is the lowest rating and 5 is the highest rating. The rating will replace the previous rating.



Ø  What must “play” do?

The “play” command must allow the user to select a song, and must start “playing” each song in order from the current song. “Playing” the song for this assignment means displaying the contents of the record that represents the song for a short period of time, clearing the screen and showing the next record in the list, etc. This continues until all songs have been played.



Ø  What must “exit” do?

The “exit” command saves the most recent list to the musicPlayList.csv file. This command will completely overwrite the previous contents in the file.

*/
