#include "Tree.h"

Tree::Tree()
{
	Node *root = new Node();
	root->setChar('F');
	root->setCode("..-.");
	this->mpRoot = root; // empty tree 'F' is root: I took Z ascii code which is 90 and - half of the total dictionary 
						//list which is 20 and it landed on 'F' or code 70. this is the most balanced it can be including numbers

}

Tree::~Tree()
{
	deleteTree(mpRoot);
}
void Tree::deleteTree(Node *pHead)
{
	if (pHead != NULL) {
		deleteTree(pHead->getRightPtr());
		deleteTree(pHead->getLeftPtr());
		delete pHead;
	}
}

void Tree::insert(char newChar, string newString)
{
	insert(this->mpRoot, newChar, newString);
}
void Tree::insert(Node *pTree, char newChar, string newString) //Andy starter Code
{
	if (pTree == nullptr) // empty tree
	{
		string *pInt = new string;
		*pInt = newString;
		char *temp = new char;
		*temp = newChar;
		this->mpRoot = new Node(&newChar, &newString);
	}
	else // recursive step - tree is not empty
	{
		if (newChar < pTree->getChar())
		{
			if (pTree->getLeftPtr() != nullptr)
			{
				insert(pTree->getLeftPtr(), newChar, newString);
			}
			else
			{
				// found place to insert in left subtree
				string *pInt = new string;
				*pInt = newString;
				char *temp = new char;
				*temp = newChar;
				pTree->setLeftPtr(new Node(&newChar, &newString));
			}
		}
		else if (newChar > pTree->getChar())
		{
			// go down right subtree
			if (pTree->getRightPtr() != nullptr)
			{
				insert(pTree->getRightPtr(),newChar, newString);
			}
			else
			{
				// insert
				string *pInt = new string;
				*pInt = newString;
				char *temp = new char;
				*temp = newChar;
				pTree->setRightPtr(new Node(&newChar, &newString));
			}
		}
		else // duplicate value
		{
			cout << "duplicate: " << newChar << endl;
		}
	}
}

Node Tree::getRoot()
{
	return *mpRoot;
}

string Tree::searchTreeChar(Node *pTree, char term) //seearching by char for morse string
{
	if (term == pTree->getChar())
	{
		return pTree->getCode();
	}
	if (term > pTree->getChar())
	{
		return searchTreeChar(pTree->getRightPtr(), term);
	}
	if (term < pTree->getChar())
	{
		return searchTreeChar(pTree->getLeftPtr(), term);
	}
}
//
//char Tree::searchTreeString(Node *pTree, string term) // I guess I dont need to do this
//{
//	char x = '\0';
//	if (term == pTree->getCode())
//	{
//		return pTree->getChar();
//	}
//	else if (pTree != nullptr)
//	{
//		x = searchTreeString(pTree->getLeftPtr(),term);
//		if (x == '\0')
//		{
//			x = searchTreeString(pTree->getRightPtr(), term);
//		}
//		return x;
//	}
//}

void Tree::print(Node *root) 
{
	if (root != NULL) {
		print(root->getLeftPtr());  // print left subtree
		cout << root->getChar() << "  "; // print this node
		print(root->getRightPtr()); // print right subtree
	}
}
