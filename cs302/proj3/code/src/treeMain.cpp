//Nicholas Ang
//Main CPP file

//Libraries and Header Files
#include "BinaryNodeTree.h"
#include "BinarySearchTree.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"

#include "BinarySearchTree.cpp"
#include "PrecondViolatedExcept.cpp"
#include "NotFoundException.cpp"

#include <iostream>
#include <ctime>
using namespace std;

//Function declarations
int generateRandom();
void visit(int &item);

//Main function
int main()
{
//Variables
int rand;
int maxSize = 100;
int caseNum;
int arr[maxSize];
BinarySearchTree<int> tree;

//Seed set to NULL for generateRandom function to be able to generate random numbers
srand(time(NULL));

//Menu Implementation
do
{
//Menu 
cout << "MENU" << endl <<  "1. Generate Random Tree Values" << endl << "2. Preorder Traversal"<< endl << "3. Inorder Traversal"<< endl << "4. Postorder Traversal" << endl << "5. EXIT" << endl;
cin >> caseNum;
switch(caseNum)
{
		//Option 1: clears the tree before adding values to binary search tree
		//Random numbers are added to tree
		//Also outputs height of created tree and values of tree
	case 1: tree.clear();
		for(int i = 0; i < maxSize; i++)
		{
			rand = generateRandom();
			//If the value is not unique, decrement i and try to find a unique value
			if(tree.contains(rand) == true)
			{
				i--;
			}
			//Value is unique so add to binary search tree in appropriate spot
			else
			{
				arr[i] = rand;
				tree.add(rand);
			}
		}
		//Output messages - height, values 
		cout << "Tree has been generated" << endl;
		cout << "Height of Tree: " << tree.getHeight() << endl;
		cout << "Values Generated: " << endl;
		for(int i = 0; i < maxSize; i++)
		{
		cout << arr[i] << endl;
		}
		cout << endl;
		break;

		//Preorder Traversal of BST - calls preorderTraverse method from Binary Search Tree class
	case 2: cout << "Preorder Traversal: " << endl;
		tree.preorderTraverse(visit);
		cout << endl;
		break;
	
		//Inorder Traversal of BST - calls inorderTraverse method from Binary Search Tree class
	case 3: cout << "Inorder Traversal: " << endl;
		tree.inorderTraverse(visit);
		cout << endl;
		break;

		//Postorder Traversal of BST - calls postorderTraverse method from Binary Search Tree class
	case 4: cout << "Postorder Traversal: " << endl;
		tree.postorderTraverse(visit);
		cout << endl;
		break;
		
		//If option 5 is selected, stop program
	case 5: break;
}

}
while(caseNum != 5);

return 0;
}

//Generate Random function - outputs a random number from 1 - 200
int generateRandom()
{
	int randNum;
	randNum = rand() % 200 + 1;
	return randNum;
}

//Defined Visit function - outputs item it traverses to
void visit(int &item)
{
	cout << item << endl;
}
