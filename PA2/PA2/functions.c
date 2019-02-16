#include "Header.h"


/*
Programmer: Erik Handeland
Assignment: PA 2/3
Description: Music manager that reads in song vs CVS file and allows user to play/edit
*/

int menu(int *selection)
{
	do
	{
		puts("       _       _        _                 ____   ___   ___  ");
		puts("      | |     | |      | |               |___ \\ / _ \\ / _ \\ ");
		puts("      | |_   _| | _____| |__   _____  __   __) | | | | | | |");
		puts("  _   | | | | | |/ / _ \\ '_ \\ / _ \\ \\/ /  |__ <| | | | | | |");
		puts(" | |__| | |_| |   <  __/ |_) | (_) >  <   ___) | |_| | |_| |");
		puts("  \\____/ \\__,_|_|\\_\\___|_.__/ \\___/_/\\_\\ |____/ \\___/ \\___/ \n\n");
                                                           


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
		printf("(11) \texit\n");
		printf("(12) \tAndy's Mix Tape\n\n");

		scanf("%d", &selection);
		clear_Screen();
	} while (selection < 1 || selection > 12);

	return selection;
}


/////////////// Load Data

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
		else
		{
			pNew->data = Data;
		}
		*pHead = pNew;
	}
}

void load(FILE *infile, Node **pHead, int *nodes)
{
	Record data;
	char temp[100] = "line";
	int index = 0;
	char time[10] = { '\0' };
	while (!feof(infile))
	{
		
		fgets(temp, 100, infile);
		if (temp[0] == '\"')
		{
			strcpy(data.artist, strtok(temp, "\""));
		}
		else
		{
			strcpy(data.artist, strtok(temp, ","));
		}
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
	*nodes = index;
}

int isEmpty(Node *pHead) // Taken from O'Fallon Starter code
{
	return (pHead == NULL);
}

/////////////// Store Data
int store(FILE *infile, Node **pHead)
{
	
	if (*pHead != NULL && (*pHead)->pNext != NULL)
	{
		fprintf(infile, "\"%s\"%s,%s,%s,%d:%d,%d,%d\n", (*pHead)->data.artist, (*pHead)->data.album, (*pHead)->data.song, (*pHead)->data.genre,
			(*pHead)->data.minutes, (*pHead)->data.seconds, (*pHead)->data.playCount, (*pHead)->data.Rating);
		*pHead = (*pHead)->pNext;
		store(infile, &(*pHead));
	}
	else if (*pHead != NULL && (*pHead)->pNext == NULL) // last node
	{
		fprintf(infile,  "\"%s\"%s,%s,%s,%d:%d,%d,%d", (*pHead)->data.artist, (*pHead)->data.album, (*pHead)->data.song, (*pHead)->data.genre,
			(*pHead)->data.minutes, (*pHead)->data.seconds, (*pHead)->data.playCount, (*pHead)->data.Rating);
	}
	else
	{
		return 0;
	}

}

///////////////  Display Data
int display(Node **pHead)
{
	int option = 0;
	char search[MAX] = { '\0' };
	Node *temp = *pHead;
	do
	{
		printf("1. \t print all records\n");
		printf("2. \t print all records that match an artist\n");
		scanf("%d", &option);
		clear_Screen();

	} while (option < 1 && option > 2);

	if (option == 1)
	{
		printAll(temp);
	}
	else if(option == 2)
	{
		printf("Enter the name of an artist to search \n");
		scanf("%s", search);
		printSearch(temp, search);

	}
}

int printSearch(Node *temp, char search[MAX])
{
	int matches = 0;
	int length = strlen(search) - 1;
	double accuracy = 0;

	if (temp != NULL && temp->pNext != NULL)
	{
		for (int i = 0; i < length && i < strlen(temp->data.artist); i++)
		{
			if (temp->data.artist[i] == search[i])
			{

				matches++;
			}
		}
		accuracy = (double)matches / length * 100;
		if (accuracy > 75) //used to see if a majority of the users seach matchs an artist
		{
			printf("%s \t %s \t %s \t %s \t %d:%d \t %d \t %d \n", temp->data.artist, temp->data.album, temp->data.song, temp->data.genre,
				temp->data.minutes, temp->data.seconds, temp->data.playCount, temp->data.Rating);
		}
		temp = temp->pNext;
		printSearch(temp, search);
	}
	else
	{
		return;
	}

}

int printAll(Node *temp)
{
	if (temp != NULL && temp->pNext != NULL)
	{
		printf("%s \t %s \t %s \t %s \t %d:%d \t %d \t %d \n", temp->data.artist, temp->data.album, temp->data.song, temp->data.genre,
			temp->data.minutes, temp->data.seconds, temp->data.playCount, temp->data.Rating);
		temp = temp->pNext;
		printAll(temp);
	}
	else if (temp != NULL && temp->pNext == NULL) // last node
		{
			printf("%s \t %s \t %s \t %s \t %d:%d \t %d \t %d \n", temp->data.artist, temp->data.album, temp->data.song, temp->data.genre,
				temp->data.minutes, temp->data.seconds, temp->data.playCount, temp->data.Rating);
			temp = temp->pNext;
			printAll(temp);
		}
	else
	{
		return;
	}
}

/////////////// Insert Data
int insert(Node **pHead, int test)
{
	if (test == 1)
	{
		Record data;
		strcpy(data.artist, "Perry, Katy");
		strcpy(data.album, "Witness");
		strcpy(data.song, "Chained to the Rhythm");
		strcpy(data.genre, "pop");
		data.minutes = 4, data.seconds = 36, data.playCount = -1, data.Rating = 6;
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->pPrev = NULL;

		newNode->data = data;
		newNode->pNext = *pHead;
		*pHead = newNode;

	}
	else
	{
		char temp;
		scanf("%c");
		Record newData;
		printf("Enter a new record below: \n");
		newData = getData();
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->pPrev = NULL;

		newNode->data = newData;
		newNode->pNext = *pHead;
		*pHead = newNode;
	}
}

Record getData()
{
	char temp[5]; // stores numbers
	Record Data;
	printf("New Data\n Artist:  ");
	fgets(Data.artist, MAX, stdin);
	printf("\n Album:  ");
	fgets(Data.album, 30, stdin);
	printf("\n Song:  ");
	fgets(Data.song, 30, stdin);
	printf("\n Genre:  ");
	fgets(Data.genre, 30, stdin);
	printf("\n Minutes:  ");
	fgets(temp, 4, stdin);
	Data.minutes = atoi(temp);
	printf("\n Seconds:  ");
	fgets(temp, 4, stdin);
	Data.seconds = atoi(temp);
	printf("\n Play Count:  ");
	fgets(temp, 4, stdin);
	Data.playCount = atoi(temp);
	printf("\n Rating:  ");
	fgets(temp, 4, stdin);
	Data.Rating = atoi(temp);

	for (int i = 0; i < 49; i++) // cleans data ... removes \n
	{
		if (Data.artist[i] == '\n')
		{
			Data.artist[i] = '\0';
		}
		if (Data.album[i] == '\n')
		{
			Data.album[i] = '\0';
		}
		if (Data.song[i] == '\n')
		{
			Data.song[i] = '\0';
		}
		if (Data.genre[i] == '\n')
		{
			Data.genre[i] = '\0';
		}
	}
	clear_Screen();
	return Data;
}

/////////////// Delete Node
int deleteNode(Node **pHead, char song[])
{
	Record newData;
	Node *cur = NULL;
	Node *remove = NULL;
	cur = *pHead;

	int SM = 0;
	int SL = strlen(song) - 1;
	double SA = 0;


	for (int i = 0; cur->pNext != NULL; i++)
	{
		for (int x = 0; x < SL && x < strlen(cur->data.song); x++)
		{
			if (cur->data.song[x] == song[x])
			{
				SM++;
			}

		}
		SA = (double)SM / SL * 100;
		if (SA > 75)
		{
			remove = cur;
			cur->pPrev->pNext = cur->pNext;
			return;
		}
		cur = cur->pNext;
		free(remove);
	}
	if (cur != NULL && cur->pNext == NULL) // one node or last node
	{
		remove = cur;
		free(remove);
	}
	return;
}

/////////////// Edit Node
int edit(Node **pHead, char song[], char artist[], int rate)
{
	Record newData;
	if (rate < 1)
	{
		newData = getData();
	}
	Node *cur = NULL;
	cur = *pHead;

	int SM = 0, AM = 0; // song and artist matchses
	int SL = strlen(song) - 1, AL = strlen(artist) -1; //song and artist length
	double SA = 0, AA = 0; //accuracy
	int passes = 0;

	for (int i = 0; cur->pNext != NULL; i++)
	{

		for (int x = 0; x < AL && x < strlen(cur->data.artist); x++) // Artist
		{
			if (cur->data.artist[x] == artist[x])
			{
				AM++;
			}
		}
		for (int x = 0; x < SL && x < strlen(cur->data.song); x++)
		{
			if (cur->data.song[x] == song[x])
			{
				SM++;
			}

		}
		SA = (double)SM / SL * 100;
		AA = (double)AM / AL * 100;
		if (SA > 75 && AA >75) //used to see if a majority of the users seach matchs an artist
		{
			if (rate > 0)
			{
				char temp[5];
				printf("Rating:");
				fgets(temp, 4, stdin);
				cur->data.Rating = atoi(temp);
				printf("\n %s %s %s %s %d:%d %d %d \n", cur->data.artist, cur->data.album, cur->data.song, cur->data.genre,
					cur->data.minutes, cur->data.seconds, cur->data.playCount, cur->data.Rating);

			}
			else
			{
				cur->data = newData;
				printf("\n %s %s %s %s %d:%d %d %d \n", cur->data.artist, cur->data.album, cur->data.song, cur->data.genre,
					cur->data.minutes, cur->data.seconds, cur->data.playCount, cur->data.Rating);
			}
			return;
		}
		passes++;
		cur = cur->pNext;
	}
	return;
}

/////////////// Play Node
int play(Node *pHead) //changes head node
{
	char artist[MAX] = { '0' };
	char song[MAX] = { '0' };
	char temp;
	Record *head = &(*pHead).data;
	Record *data = (Record *)malloc(sizeof(Record));;

	scanf("%c", &temp);
	printf("\n Artist:  ");  //gets users search query
	fgets(artist, MAX, stdin);
	printf("\n\nSong: ");
	fgets(song, MAX, stdin);
	*data = searchNode(pHead, song, artist); //sets head to current current searched song
	printf("%s %s %s %s %d:%d %d %d \n\n", (*data).artist, (*data).album, (*data).song, (*data).genre,
		(*data).minutes, (*data).seconds, (*data).playCount, (*data).Rating);
	delay(3);
	clear_Screen();
}

Record searchNode(Node *pHead, char song[], char artist[])
{
	int SM = 0, AM = 0; // song and artist matchses
	int SL = strlen(song) - 1, AL = strlen(artist) - 1; //song and artist length
	double SA = 0, AA = 0; //accuracy
	int passes = 0;
	Record *data = (Record *)malloc(sizeof(Record));;
	for (int i = 0; pHead->pNext != NULL; i++)
	{

		for (int x = 0; x < AL && x < strlen(pHead->data.artist); x++) // Artist
		{
			if (pHead->data.artist[x] == artist[x])
			{
				AM++;
			}
		}
		for (int x = 0; x < SL && x < strlen(pHead->data.song); x++)
		{
			if (pHead->data.song[x] == song[x])
			{
				SM++;
			}

		}
		SA = (double)SM / SL * 100;
		AA = (double)AM / AL * 100;
		if (SA > 75 && AA > 75) //used to see if a majority of the users seach matchs an artist
		{
			data = &pHead->data;
			break;
		}
		passes++;
		pHead = pHead->pNext;
	}
	for (int i = 0; i < passes; i++) // reset head
	{
		pHead = pHead->pPrev;
	}
	passes = 0;
	return *data;
}

int displayNode(Node *pHead)
{
	if (pHead != NULL && pHead->pNext != NULL)
	{
		printf("%s %s %s %s %d:%d %d %d \n\n", pHead->data.artist, pHead->data.album, pHead->data.song, pHead->data.genre,
			pHead->data.minutes, pHead->data.seconds, pHead->data.playCount, pHead->data.Rating);
		pHead = pHead->pNext;
		delay(3);
		clear_Screen();
		displayNode(pHead);
	}
	else
	{
		return;
	}
}

void delay(int number_of_seconds) // Code from geeks for geeks Creates a second delay
{
	// Converting time into milli_seconds 
	int milli_seconds = 1000 * number_of_seconds;

	// Stroing start time 
	clock_t start_time = clock();

	// looping till required time is not acheived 
	while (clock() < start_time + milli_seconds)
		;
}


/////////////// Shuffle Node
int shuffle(Node *pHead, int node_size)
{
	Node *shuffle_list = pHead;
	int played[MAX] = { 0 };
	shuffle_array(played, node_size);
	for (int i = 0; i <= node_size -1; i++)
	{
		for (int t = 0; t <= played[i]; t++)
		{
			if (t == played[i])
			{
				printf("%s %s %s %s %d:%d %d %d \n\n", shuffle_list->data.artist, shuffle_list->data.album, shuffle_list->data.song, shuffle_list->data.genre,
					shuffle_list->data.minutes, shuffle_list->data.seconds, shuffle_list->data.playCount, shuffle_list->data.Rating);
				delay(3);
				shuffle_list = pHead; //resets to front
			}
			else
			{
				shuffle_list = shuffle_list->pNext;
			}
		}
	}
	cont_promt();
	clear_Screen();
}

int shuffle_array(int shuffle[MAX], int node_size)
{
	int random = rand(time) % (node_size - 1);
	int temp = 0;
	for (int i = 0; i < node_size; i++)
	{
		shuffle[i] = i;
	}
	for (int i = 0; i < node_size; i++)
	{
		random = rand(time) % (node_size - 1);
		temp = shuffle[random];
		shuffle[random] = shuffle[i];
		shuffle[i] = temp;
	}
	temp = 0;
}

/////////////// Sort Node

int sort_menu(Node **pHead, int node_size)
{
	int select = 0;
	do
	{
		printf("Please select an option to sort by\n\n");

		printf("(1)   \tArtist\n");
		printf("(2)   \tAlbum\n");
		printf("(3)   \tRating\n");
		printf("(4)   \tPlay Count\n\n");
		scanf("%d", &select);
		clear_Screen();
	} while (select < 1 || select > 4);

	switch (select)
	{
	case 1:
		sort_artist(pHead, node_size);
		break;
	case 2:
		sort_Album(pHead, node_size);
		break;
	case 3:
		sort_Rating(pHead, node_size);
		break;
	case 4:
		sort_PlayCount(pHead, node_size);
		break;
	default:
		break;
	}
}

int switchNodes(Node **a, Node **b, Record *data)
{

	*data = (*a)->data;
	(*a)->data = (*b)->data;
	(*b)->data = *data;

	//trash code
	/*
	*data = a->data;
	Node *temp = a;

	a->pNext = data;		//inter pointer
	
	a->data = b->data;		//sets data
	b->data = *data; 	

	b->pPrev = a;			//inter pointer
	*/
}

int sort_artist(Node **pHead, int node_size)
{
	Node *cur = *pHead;
	Record *data = (Record *)malloc(sizeof(Record));
	Node *start = *pHead;

	for (int match = 0; match < 50; match++)
	{
		//match = 0;
		for (int i=0; cur->pNext->pNext != NULL; i++) 
		{
			if (cur->data.artist[0] <= cur->pNext->data.artist[0])
			{
				//match++;
			}
			else
			{
				switchNodes(&cur, &cur->pNext, data);
			}
			cur = cur->pNext;
		}
		cur = start;
	}
	int done = 0;
}

int sort_Album(Node **pHead, int node_size)
{
	Node *cur = *pHead;
	Record *data = (Record *)malloc(sizeof(Record));
	Node *start = *pHead;

	for (int match = 0; match < 50; match++)
	{
		//match = 0;
		for (int i = 0; cur->pNext->pNext != NULL; i++)
		{
			if (cur->data.album[0] <= cur->pNext->data.album[0])
			{
				//match++;
			}
			else
			{
				switchNodes(&cur, &cur->pNext, data);
			}
			cur = cur->pNext;
		}
		cur = start;
	}
}

int sort_Rating(Node **pHead, int node_size)
{
	Node *cur = *pHead;
	Record *data = (Record *)malloc(sizeof(Record));
	Node *start = *pHead;

	for (int match = 0; match < 50; match++)
	{
		//match = 0;
		for (int i = 0; cur->pNext->pNext != NULL; i++)
		{
			if (cur->data.Rating <= cur->pNext->data.Rating)
			{
				//match++;
			}
			else
			{
				switchNodes(&cur, &cur->pNext, data);
			}
			cur = cur->pNext;
		}
		cur = start;
	}
}

int sort_PlayCount(Node **pHead, int node_size)
{
	Node *cur = *pHead;
	Record *data = (Record *)malloc(sizeof(Record));
	Node *start = *pHead;

	for (int match = 0; match < 50; match++)
	{
		//match = 0;
		for (int i = 0; cur->pNext->pNext != NULL; i++)
		{
			if (cur->data.playCount <= cur->pNext->data.playCount)
			{
				//match++;
			}
			else
			{
				switchNodes(&cur, &cur->pNext, data);
			}
			cur = cur->pNext;
		}
		cur = start;
	}
	int done = 0;
}
/////////// Simple functions
int clear_Screen()
{
	system("cls");
}

int cont_promt()
{
	/*
	printf("\n Press any key folllowed by Enter to continue \n \n");
	char c = NULL;
	while (c == '\n' || c == NULL)
		c = getchar();
	*/
	char temp;
	scanf("%c");
	printf("\n Press Enter to continue \n \n");
	getchar();
	clear_Screen();
}


int play_song()
{
	printf("Song with end in 30 seconds\n");
	puts("...................... ...........................,-~~******'~~-,,_");
	puts("....................... .......................,-~**-,::::::::::::**-,");
	puts("....................... ....................,~**::::',:::::::::::::::|',");
	puts("....................... ....................|::::::,-~**~~-~**~~-~**':}");
	puts("....................... ....................'|::::|: : :__  : : __: :");
	puts("....................... ....................|::::|: : :-##: :  :##-:|");
	puts("....................... ...................(_**~-': : : : : |\"");
	puts("....................... ....................**'~-,|: :  : ______':: :,'-never gonna");
	puts("....................... ......................|,: : : : :|______|:/ -give you up!");
	puts("....................... ...................,-**\':\:'~,,_: : : _,-'");
	puts("....................... ...............__,-';;;;\:**-,: ::'~-~**/|");
	puts("....................... .........__,-~**;;;;/;;;;\: :\: : :____/: :',__");
	puts("....................... .,-~~~****_;;;;;;;;;',. .**-,:|:::::::|. . |;;;;**-,__");
	puts("......................./;;;;;;;;;;;;;;;;;;;;;\. . .**|::::::::|. .,';;;;;;;;;;**-,");
	puts(".....................,' ;;;;;;;;;;;;;;|;;;;;;;;;\. . .\:::::,'. ./|;;;;;;;;;;;;;|");
	puts("....................,-**;;;;;;;;;;;;;;;;;\;;;;;;;',: : __|. . .|;;;;;;;;;,';;|");
	puts("..................,-**;;;;;;;;;;;;;;;;;;;;;;',;;;;; \. . |:::|. . .**,;;;;;;;;|;;/");
	puts("................./;;;;;;;;;;;;;;;;;|;;;;;;\;;;;;; ;;;\. .|:::|. . . |;;;;;;;;|/");
	puts(".............../;;,-';;;;;;;;;;;;;;;,';;;;;;;;; ;;;|. .\:/. . . .|;;;;;;;;|");
	puts("............../;;;;;;;;;;;;;;;;;;;;;;;;;;,;;;; ;;;;**,: |;|. . . . \;;;;;;;|");
	puts("............,~**;;;;;;;;;; ;;;;;;;;;;;,-**;;;\;;;;;;;;|.|;|. . . . .|;;;;;;;|");
	puts("..........,~**;;;;;;;;;;;;;; ;;;;;;;;,-';;;;;;',;;;;;;| |:|. . . . |\;;;;;;;|");
	puts(".........,';;;;;;;;;;;;;;;;; ;;;;;;;/;;;,-';;;;;;;;;;;| |:|. . . .'|;;',;;;;;|");
	puts("........|;,-';;;;;;;;;;;;;;;;;;;,-';;;,-';;;;;;;;;;;;;| |:|. . .,';;;;;',;;;;|_");
	puts("........./;;;;;;;;;;;;;;;;;,-'_;;;;;;,';;;;;;;;;|;;;; ;|.|:|. . .|;;;;;;;|;;;;|****~-,");
	puts("......../;;;;;;;;;;;;;;;;;;/_**,;;;,';;;;;;;;;::;;; ,;;| |:|. . ./;;;;;;;;|;;;|;;;;;;|-,,__");
	puts("......./;;;;;;;;;;;;;;;;;,-'..|;;,;;;;;;;; ;Scroll Up:;| |:|._,-';;;;;;;;;|;;;;|;;;;;;;;;;;**'-,_");
	puts("Posted in ASCII Art | Tagged A");

	PlaySound(TEXT("MixTape.wav"), NULL, SND_FILENAME);
	clear_Screen();
}

/*

Bugs
 case 8 rate: user can enter any number
 getData user any enter any number for rate not 1-5

 During multiple things without closing the program causes failure or data corruption
*/