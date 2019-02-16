#include "Header.h"

int main()
{	
	int selection = 0; //menu selection
	int *ptr_selection = selection;
	

	int num_song = 0; // used to know how many nodes created
	int *ptr_song = &num_song;
		
	FILE *infile = NULL;

	Node *pHead = (Node *)malloc(sizeof(Node));
	pHead = NULL;

	//case 4 - Edit
	char artist[MAX] = { '0' }; //user search terms
	char song[MAX] = { '0' };
	char temp; //used to collect hanging \n from continue commands

	//case 8
	int rate = 0; // used to change edit function


	/////////////// Test Functions
	//test_insert(&pHead);
	//test_delete(&pHead);
	//test_shuffle(&pHead);
	//pHead = NULL;

	
	selection = menu(ptr_selection);
	do
	{
		switch (selection)
		{
		case 1: //load
			if (!pHead)
			{
				infile = fopen("musicPlayList.csv", "r+");
				load(infile, &pHead, ptr_song);
				fclose(infile);
			}
			printf("Data has been loaded\n");
			cont_promt();
			selection = menu(ptr_selection);
			break;
		case 2://store
			if (pHead != NULL)
			{
				infile = fopen("musicPlayList.csv", "w+");
				store(infile, &pHead);
				fclose(infile);
				printf("Data has been stored\n");
			}
			cont_promt();
			selection = menu(ptr_selection);
			break;
		case 3: //display
			display(&pHead);
			cont_promt();
			selection = menu(ptr_selection);
			break;
		case 4: //insert
			insert(&pHead, 0);
			printf("Data has been added\n");
			cont_promt();
			selection = menu(ptr_selection);
			break;
		case 5: //delete
			if (pHead != NULL)
			{
				scanf("%c", &temp);
				printf("\n\nSong: ");
				fgets(song, MAX, stdin);
				deleteNode(&pHead, song);
				printf("Data has been delete\n");
			}
			cont_promt();
			selection = menu(ptr_selection);
			break;
		case 6: //edit
			if (pHead != NULL)
			{
				scanf("%c", &temp);
				printf("\n Artist:  ");
				fgets(artist, MAX, stdin);
				printSearch(pHead, artist);
				printf("\n\nSong: ");
				fgets(song, MAX, stdin);
				edit(&pHead, song, artist, rate);
				printf("\n ^ Data has been edited \n");
			}
			cont_promt();
			selection = menu(ptr_selection);
			break;
		case 7: // sort
			if (pHead != NULL)
			{
				sort_menu(&pHead, num_song);
			}
			printf("\n ^ Data has been sorted \n");
			cont_promt();
			selection = menu(ptr_selection);
			break;
		case 8: //rate
			if (pHead != NULL)
			{
				rate++; // tells edit thats we are changeing rating;
				scanf("%c", &temp);
				printf("\n Artist:  ");
				fgets(artist, MAX, stdin);
				printSearch(pHead, artist);
				printf("\n\nSong: ");
				fgets(song, MAX, stdin);
				edit(&pHead, song, artist, rate);
				printf("\n ^ The Rating has changed \n");
			}
			cont_promt();
			selection = menu(ptr_selection);
			break;
		case 9: //play
			if (!pHead)
			{
				play(pHead);
			}
			selection = menu(ptr_selection);
			break;
		case 10: //shuffle currupts a lot of the code: pHead, num_song
			if (pHead != NULL)
			{
				shuffle(pHead, num_song); // deletes Null pointer
			}
			pHead = NULL; // since it deletes pointer anyway I set it to NUll so that my exit function doent write bad data.
			selection = menu(ptr_selection);
		case 11: //exit
			if (pHead != NULL)
			{
				infile = fopen("musicPlaylist.csv", "w+");
				store(infile, &pHead);
				fclose(infile);
			} 
			return 0;
		case 12: //for fun
			play_song();
			selection = menu(ptr_selection);
			break;
		default:
			break;
		}
	} while (selection > 0 || selection < 13);
	return 0;
}
