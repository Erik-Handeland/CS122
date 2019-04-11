#pragma once
#include "Header.h"
#include "Node.h"



class Tree
{
public:
	Tree();
	~Tree();

	Node getRoot(); //used for  printing
	string searchTreeChar(Node *pTree, char term);
	//char searchTreeString(Node *pTree, string term); //Didnt have to do, also didnt finish
	void print(Node *root);
	void insert(char newChar, string newString); //Andy starter Code



private:
	void deleteTree(Node *pHead);
	Node *mpRoot;
	void insert(Node *pTree, char newChar, string newString);
};
