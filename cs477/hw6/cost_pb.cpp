//Nicholas Ang
//Part B of Hw6,Q1

//Libraries
#include <iostream>
#include <fstream>
using namespace std;

//Array size for number of weeks
#define arraySize 10

//Function declarations
void optimalPath(int arr[], int optMatrix[], int c, int r);

//Main function
int main()
{
	//Given values and variables
	int s[] = {11, 9, 9, 12, 12, 12, 12, 9, 9, 11};
	int r = 1;
	int c = 10;
	int optimalMatrix[arraySize];
	//Set array values to 0
	for(int i = 0; i < arraySize; i++)
	{
		optimalMatrix[i] = 0;
	}
	
	//Calls the optimalPath function
	optimalPath(s,optimalMatrix,c,r);
	
	//File output
	ofstream file;
	file.open("cost_pb_out.txt");
	file << "Optimal Values to all subproblems: " << endl;
	for(int i = 0; i < arraySize; i++)
	{
		file << optimalMatrix[i] << " ";
	}
	file << endl;
	//Output final solution
	file << endl << "Optimal Cost: " << optimalMatrix[arraySize-1];
	file.close();
	return 0;
}

//Optimal Path function
void optimalPath(int arr[], int optMatrix[], int c, int r)
{
//Iterates through entire array
for(int i = 0; i < arraySize; i++)
{
	//Checks if the first value in the given arr[i] is > 4*c, and sets optMatrix[i] to lesser value of the two
	if(i == 0)
	{
		if(0 + (r*arr[i]) < (0 + (4*c)))
		{
			optMatrix[i] = 0 + (r*arr[i]);
		}
		else
		{
			optMatrix[i] = 0 + (4*c);
		}
	}
	//Checks if the 2nd and third values in the given arr[i] is > 4*c, and sets optMatrix[i] to lesser value of the two
	else if(i-3 <= 0 && i > 0)
	{
		if(optMatrix[i-1] + (r*arr[i]) < (0 + (4*c)))
		{
			optMatrix[i] = optMatrix[i-1] + (r*arr[i]);
		}
		else
		{
			optMatrix[i] = 0 + (4*c);
		}
	}
	//When i is four or more, the lesser of optMatrix[i-1] + (r*arr[i]) and (optMatrix[i-4] + (4*c)) 
	//is placed into optMatrix[i]
	else if(i-3 > 0 && i > 0)
	{
			if(optMatrix[i-1] + (r*arr[i]) < (optMatrix[i-4] + (4*c)))
			{
				optMatrix[i] = optMatrix[i-1] + (r*arr[i]);
			}
			else
			{
				optMatrix[i] = optMatrix[i-4] + (4*c);
			}
		
	}
}

}

