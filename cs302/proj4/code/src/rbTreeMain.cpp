//Nicholas Ang
//Project 4 Main File


//Libraries and Header Files
#include <iostream>
#include "LeftLeaningRedBlack.h"
#include "VoidRef.h"
#include <ctime>
using namespace std;

//Generate Random Values function (1-300)
uint32_t generateRandom();

//Main Function
int main()
{
	//Seeding random generator
	srand(time(NULL));

	LeftLeaningRedBlack test;
	uint32_t arr[10];

	//For Loop to insert 10 random values from 1-300 into llrbt
	for(int i = 0; i < 10; i++)
	{
		uint32_t randNum = generateRandom();

		//Calls NewNode function to create a new node in the tree
		LLTB_t *test_node = test.NewNode();

		//Unlikely to generate same value
		for(int j = 0; j < i; j++)
		{
			if(randNum == arr[j])
			{
			randNum = generateRandom();
			}
		}

		//Sets node key value to generated value
		arr[i] = randNum;
		test_node->Ref.Key = arr[i];
		bool success = test.Insert(test_node->Ref);

		//Outputs Color after insertion and immediate Parent
		cout << "Value Inserted: " << test_node->Ref.Key << " and ";

		//Checks if inserted node is red after insertion
		if(test.findInsert(arr[i])->IsRed == true)
		{
			cout << "Color: Red" << endl;
		}
		else
		{
			cout << "Color: Black" << endl;
		}

		//Finds the parent of inserted node
		if(test.findParent(test_node->Ref.Key) == nullptr)
		{
			cout <<"This is a Root" << endl ;
		}
		else
		{
			cout << "The immediate parent of " << test_node->Ref.Key << " is " << test.findParent(test_node->Ref.Key)->Ref.Key << " with " ;
		}

		//Checks if inserted node is the root first then checks parent if not root
		if(test.findParent(arr[i]) != nullptr)
		{
			if(test.findParent(arr[i])->IsRed == true)
			{
				cout << "Color: Red" << endl;
			}
			else
			{
				cout << "Color: Black" << endl;
			}
		}
		else
		{

		}
	}
	//Traverses the tree inorder, outputing value, color, parent, and parent color
	cout << endl << "Inorder Traversal of Tree" << endl << endl;
	test.Traverse();
	cout << endl << endl;
	//Remove the 4th inserted value
	cout << "Deleting 4th insert..." << endl;
	test.Delete(arr[3]);
	//Traverses inorder but with 4th value removed
	test.Traverse();

	return 0;
}

//Generates and returns random value from 1-300
uint32_t generateRandom()
{
	uint32_t randNum;
	randNum = rand() % 300+1;
	return randNum;
}
