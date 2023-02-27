//Nicholas Ang
//Problem 2
//Implement in C/C++ a divide and conquer algorithm for finding the values of both the largest and the smallest element in an array of numbers. Show how your algorithm runs on the input 
//A = [1 4 9 3 4 9 5 6 9 3 7].
//Algorithm written on pdf
//I compiled using g++ -o problem2 problem2.cpp

//Libraries 
#include <iostream>
using namespace std;

//Function Declaration
void minMax (int arr[], int low, int high);

//Global min and max variables
int minV = 1000, maxV = 0;

//Main Function
int main()
{
	//Given Array
	int A[] = {1,4,9,3,4,9,5,6,9,3,7};
	int size = 11;
	//Set min and max to middle of array
	minV = A[((size-1)/2)];
	maxV = A[((size-1)/2)];
	//Call minMax function to find min and max
	minMax(A, 0, size-1);
	cout << "Max of Array is: " << maxV << endl;
	cout << "Min of Array is: " << minV << endl;
	return 0;
}

//minMax Function
//Inputs array, start of array, end of array
void minMax (int arr[], int low, int high)
{
	//Pivot is middle of array
	int pivot = ((low+high)/2);
	//If there is one element at the end of creating subarrays
	//Compare element with the min and max values
	if((high-low) == 0)
	{
		if(arr[low] < minV)
		{
		minV = arr[low];
		}
		else if (arr[low] > maxV)
		{
		maxV = arr[low];
		}
		return;
	}
	//If there are two elements at the end of creating subarrays
	//Compare right side/high end with the min and max values
	//Then compare the left side/low end with the min and max values
	if((high-low) == 1)
	{
		if(arr[high] > maxV)
		{
		maxV = arr[high];
		}
		else if(arr[high] < minV)
		{
		minV = arr[high];
		}
		if(arr[low] > maxV)
		{
		maxV = arr[low];
		}
		else if(arr[low] < minV)
		{
		minV = arr[low];
		}
		return;
	}
	//Recursively call minMax to split the array into the subarrays 
	//from the left and right sides
	minMax (arr, low, pivot);
	minMax (arr, pivot+1, high);
}
