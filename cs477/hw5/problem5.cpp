//Nicholas Ang
//Problem 5
//Implement in C/C++, an algorithm that checks if an array of n elements is a max-heap and determine its running time
//A = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1}
//B = {10, 3, 9, 7, 2, 11, 5, 1, 6}
//Algorithm written on pdf
//I compiled using g++ -o problem5 problem5.cpp

//Libraries
#include <iostream>
using namespace std;

//Function Declarations
bool maxHeapCheck(int arr[], int size);
void outputHeapCheck(bool heap);

//Main function
int main()
{
	//Given arrays
	int A[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
	int size1 = 10;
	int B[] = {10, 3, 9, 7, 2, 11, 5, 1, 6};
	int size2 = 9;
	
	//Output yes heap or not a heap based on the heap check
	cout << "Array A: ";
	outputHeapCheck(maxHeapCheck(A, size1));
	cout << "Array B: ";
	outputHeapCheck(maxHeapCheck(B, size2));
	return 0;
}

//Output Function for heap check
void outputHeapCheck(bool heap)
{
	//If the function returns that it is heap, say Yes, heap
	if(heap == true)
	{
		cout << "YES, heap" << endl;
	}
	//If function is not heap, say Not a heap
	else
	{
		cout << "Not a heap" << endl;
	}
}

//maxHeapCheck function to check if the heap is proper max heap
bool maxHeapCheck(int arr[], int size)
{
	int i;
	//Start i with 1 to properly move through heap
	for(i = 1; i <= size; i++)
	{
		//Check if left side has valid value
		if(2*i <= size)
		{
			//if current root is less than left side, return false
			//Subtract 1 to account for i starting at 1 instead of 0
			if(arr[i-1] < arr[2*i-1])
			{
			return false;
			}
		}
		//Check if right side has valid value
		if(2*i+1 <= size)
		{
			//If current root is less than right side, return false
			//Subtract 1 to account for i starting at 1 instead of 0
			if(arr[i-1] < arr[2*i+1-1])
			{
			return false;
			}
		}
	}
	//Return true when entire heap array is checked
	return true;
}
