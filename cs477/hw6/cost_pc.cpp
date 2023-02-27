//Nicholas Ang
//Part C of Hw6,Q1

//Libraries
#include <iostream>
#include <fstream>
using namespace std;

//Given Array Size
#define arraySize 10

//Function Declarations
void optimalPath(int arr[], int optMatrix[], int c, int r, char opt[]);

//Main function
int main()
{
	//Given variables and arrays
	int s[] = {11, 9, 9, 12, 12, 12, 12, 9, 9, 11};
	int r = 1;
	int c = 10;
	//Created arrays
	int optimalMatrix[arraySize];
	char optSol[arraySize];
	//Sets array values to 0
	for(int i = 0; i < arraySize; i++)
	{
		optimalMatrix[i] = 0;
	}

	//Calls optimal path function, modified with choices
	optimalPath(s,optimalMatrix,c,r,optSol);

	//File output for subproblem solutions
	ofstream file;
	file.open("cost_pc_out.txt");
	file << "Optimal Values to all subproblems: " << endl;
	for(int i = 0; i < arraySize; i++)
	{
		file << optimalMatrix[i] << " ";
	}
	file << endl;
	file << endl << "Optimal Cost: " << optimalMatrix[arraySize-1] << endl;

	//Output for choices selected array
	file << endl << "Choices Vector: ";
	for(int j = 0; j < arraySize; j++)
	{
		file << optSol[j] << " ";
	}
	file << endl;
	file.close();
	return 0;
}

//Optimal Path function, modified to include a char array to hold choices
void optimalPath(int arr[], int optMatrix[], int c, int r, char opt[])
{
//Iterates through entire array
for(int i = 0; i < arraySize; i++)
{
	//Checks if the first value in the given arr[i] is > 4*c, and sets optMatrix[i] to lesser value of the two
	//Choices are made and placed into opt[] array
	//The choice for 'A' corresponds to 0 + (r*arr[i])
	//The choice for 'B' corresponds to 0 + (4*c)
	if(i == 0)
	{
		if(0 + (r*arr[i]) < (0 + (4*c)))
		{
			optMatrix[i] = 0 + (r*arr[i]);
			opt[i] = 'A';
		}
		else
		{
			optMatrix[i] = 0 + (4*c);
			opt[i] = 'B';
		}
	}
	//Checks if the 2nd and third values in the given arr[i] is > 4*c, and sets optMatrix[i] to lesser value of the two
	//Choices are made and placed into opt[] array
	//The choice for 'A' corresponds to optMatrix[i-1] + (r*arr[i])
	//The choice for 'B' corresponds to 0 + (4*c)
	else if(i-3 <= 0 && i > 0)
	{
		if(optMatrix[i-1] + (r*arr[i]) < (0 + (4*c)))
		{
			optMatrix[i] = optMatrix[i-1] + (r*arr[i]);
			opt[i] = 'A';
		}
		else
		{
			optMatrix[i] = 0 + (4*c);
			opt[i] = 'B';
		}
	}
	//When i is four or more, the lesser of optMatrix[i-1] + (r*arr[i]) and (optMatrix[i-4] + (4*c)) 
	//is placed into optMatrix[i]
	//Choices are made and placed into opt[] array
	//The choice for 'A' corresponds to optMatrix[i-1] + (r*arr[i])
	//The choice for 'B' corresponds to optMatrix[i-4] + (4*c)
	else if(i-3 > 0 && i > 0)
	{
			if(optMatrix[i-1] + (r*arr[i]) < (optMatrix[i-4] + (4*c)))
			{
				optMatrix[i] = optMatrix[i-1] + (r*arr[i]);
				opt[i] = 'A';
			}
			else
			{
				optMatrix[i] = optMatrix[i-4] + (4*c);
				opt[i] = 'B';
			}
		
	}
}
}
