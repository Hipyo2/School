//Nicholas Ang
//Problem 2
//Implement in C/C++ an algorithm to rearrange elements of a given array of n real numbers 
//so that all its negative elements(strictly less than zero)
//precede all its positive elements(greater than or equal to zero).
//A = [4 3 -2 0 2 9 -1 10 0 5 23 -4]
//Algorithm written on pdf
//I compiled using g++ -o problem3 problem3.cpp

//Libraries
#include <iostream>
using namespace std;

//Function Declaration
void sortNegPos(int arr[], int size);

//Main Function
int main()
{
	//Given array
	int A[] = {4,3,-2,0,2,9,-1,10,0,5,23,-4};
	int n = 12;

	//Calls the sort negatives and positives
	sortNegPos(A,n);

	//Output values
	cout << "Rearranged: ";
	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}

//Sort Negatives from Positives Function
//Rearranges negative values to precede all positive values
void sortNegPos(int arr[], int size)
{
	//j and i start at beginning of array
	int i = 0;
	int j = 0;
	int temp;
	
	//i Goes through entire array to check for negatives to swap
	for(int i = 0; i < size; i++)
	{
		//If value is negative, swap with value at j which starts at beginning of array
		if(arr[i] < 0)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			
			//j is incremented so the negative value cannot be swapped again
			j++;
		}
	}
}
