#include "Header.h"
#include "list.h"




int main()
{

	int value = 0; //menu var and declarations
	int *selection = &value;
	menu(selection);
	int subMenu = 0;

	string id; //id search var


	ifstream infileCVS, infileTXT; //file declarations 
	ofstream outfile;

	list<data> attendence;// list declarations

	do
	{
		switch (*selection)
		{
		case 1://loads list from cvs
			infileCVS.open("classList.csv");
			importCVS(attendence, infileCVS);
			infileCVS.close();
			if (!attendence.isEmpty())
			{
				cout << "Data has been loaded" << endl << endl;
			}
			else
			{
				cout << "Data failed loaded" << endl << endl;
			}
			system("pause");
			system("cls");
			menu(selection);
			break;
		case 2: // loads list from txt
			infileTXT.open("master.txt");
			importTXT(attendence, infileTXT);
			infileTXT.close();
			if (!attendence.isEmpty())
			{
				cout << "Data has been loaded" << endl << endl;
			}
			else
			{
				cout << "Data failed loaded" << endl << endl;
			}
			system("pause");
			system("cls");
			menu(selection);
			break;
		case 3://expoprts list to txt file
			if (attendence.isEmpty())
			{
				cout << "List is Empty" << endl;
			}
			else
			{
				outfile.open("master.txt");
				exportList(attendence.getHead(), outfile);
				outfile.close();
			}
			system("pause");
			system("cls");
			menu(selection);
			break;
		case 4: //marks absent
			if (attendence.isEmpty())
			{
				cout << "List is Empty" << endl;
			}
			else
			{
				markAbsences(attendence.getHead());
			}
			system("pause");
			system("cls");
			menu(selection);
			break;

		case 5: // edit attemdemce
			if (attendence.isEmpty())
			{
				cout << "List is Empty" << endl;
			}
			else
			{
				printAbsences(attendence.getHead());
				cout << "enter a student ID" << endl;
				cin >> id;
				editAbsences(attendence.getHead(), id);
			}
			system("cls");
			system("pause");
			menu(selection);
			break;
		case 6: //reports
			if (attendence.isEmpty())
			{
				cout << "List is Empty" << endl;
			}
			else
			{
				cout << "1: print most recent Absences" << endl
					<< "2: Print student with more than X Absences" << endl << endl;
				cin >> subMenu;
				system("cls");
				if (subMenu == 1)
				{
					printAbsences(attendence.getHead());
				}
				else if (subMenu == 2)
				{
					cout << "Number of Absences: " << endl;
					cin >> subMenu;
					system("cls");
					printAbsences(attendence.getHead(), subMenu);
				}
			}
			
			system("pause");
			system("cls");
			menu(selection);
			break;
		case 7: //exit
			return 0;
		default:
			break;
		}
	} while (*selection >= 1 && *selection <= 7);
}
