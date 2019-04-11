#include "Header.h"
#include "Tree.h"

int main()
{
	int selection = 0; // menu
	string search; // search string
	string token;; // max charater length not very effient count later use some sort of delmiter function to return each part of string 
	string result;


	//Build the tree
	Tree morse;
	ifstream infile, table;
	infile.open("Convert.txt");
	table.open("dictionary.txt");
	string a; //convert to char;
	string b;
	while (!table.eof())
	{
		getline(table, a, ';');
		getline(table, b);
		morse.insert(a[0],b);
	}
	//Build the tree
	system("CLS");
	cout << "Content of Tree:" << endl;
	morse.print(&morse.getRoot());
	cout << endl << endl;

	cout << "1\t Read from File" << endl
		<< "2\t Read from Keyboard" << endl;
	cin >> selection;
	if (selection == 1)
	{
		system("CLS");
		/*selection = 0;
		cout << "1\t English to Morse Code" << endl
			<< "2\t Morese Code to English" << endl;*/
	//	cin >> selection;
		if (selection == 1)
		{
			cout << "Result: ";
			while (!infile.eof())
			{
				getline(infile, search);
				for (int i = 0; i < search.length(); i++)//converts to upercase
				{
					search[i] = toupper(search[i]);
				}
				for (int i = 0; i < search.length(); i++)
				{

					result += morse.searchTreeChar(&morse.getRoot(), search[i]);
					result += " ";
				}
				cout << result << endl;
				result.clear();
			}
			system("PAUSE");
		}
		/*else if (selection == 2)
		{
		}*/
		else
		{
			cout << "Invalid Option" << endl;
			system("Pause");
			return 0;
		}
	}
	else if (selection == 2)
	{
		system("CLS");
	/*	selection = 0;
		cout << "1\t English to Morse Code" << endl
			<< "2\t Morese Code to English" << endl;
		cin >> selection;*/
		if (selection == 2) // case for reading spaces
		{
			cout << "Enter a sentence" << endl;
			cin.ignore();
			getline(cin, search);

			for (int i = 0; i < search.length(); i++)//converts to upercase
			{
				search[i] = toupper(search[i]);
			}
			
			for (int i=0; i < search.length(); i++)
			{
				
				result += morse.searchTreeChar(&morse.getRoot(), search[i]);
				result += " ";
			}
			system("CLS");
			cout << "Original " << search << endl << endl
				<< "Result: " << result << endl;
			system("PAUSE");
		}
		//else if (selection == 2) // I guess I dont need to do this
		//{
		//	cout << "Enter morse code" << endl;
		//	cin >> search;
	
		//	system("CLS");
		//	cout << "Original " << search << endl << endl;
		//	stringstream ss(search);
		//	while (getline(ss, token, ' '))
		//	{
		//		result += morse.searchTreeString(&morse.getRoot(), token);
		//	}
		//	cout  << "Result: " << result << endl;
		//	system("PAUSE");

		//}
		else
		{
			cout << "Invalid Option" << endl;
			system("Pause");
			return 0;
		}
	}
	else
	{
		cout << "Invalid Option" << endl;
		system("Pause");
		return 0;
	}
}