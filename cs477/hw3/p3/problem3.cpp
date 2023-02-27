//Nicholas Ang
//Problem 3
//Implement  Mergesort  without  a  recursion  by  starting  with  merging adjacent elements of a given array, then merging sorted pairs, and so on.
//A = [1 4 9 3 4 9 5 6 9 3 7 2].
//Algorithm written on pdf
//I compiled using g++ -o problem3 problem3.cpp

//Libraries
#include <iostream>
using namespace std;

//Function Declarations
void mergeSort(int arr[], int size);
void merge(int arr[], int p, int q, int r);


//Main functions
int main()
{
	//Given array
	int A[] = {1, 4, 9, 3, 4, 9, 5, 6, 9, 3, 7, 2};
	int size = 12;
	
	//Calls mergeSort function to sort the array
	mergeSort(A, size);
	return 0;
}

//mergeSort Function
//Inputs array and size of array
void mergeSort(int arr[], int size)
{
	int k;
	//Loops and increments i to form subarrays of size 2^i. 
	//from 1 array to 2 subarrays to 4 subarrays...
	for(int i = 1; i < size; i = ((2*i)))
	{
		//Splits the array into subarrays. 
		//the beginning of each subarray is j+2*i
		for(int j = 0; j < (size-1); j = j + ((2*i)))
		{
			//the middle element of the array is j+i-1
			int mid = (j + i - 1);
			
			//Finds the end of the subarray
			//If the end of the subarray exceeds the size of array,
			//the end of the subarray is the size-1
			if((size-1) > (2*i + j - 1))
			{
				k = (2*i + j - 1);
			}
			else
			{
				k = (size-1);
			}
			//call merge Function to merge the subarrays
			merge(arr, j, mid, k);
		}
	}
	//Output the sorted array onto the terminal
	cout << "Sorted: "; 
	for(int i = 0; i < 12; i++)
	{
	cout << arr[i] << " ";
	}
	cout << endl;
}

//merge Function
//Inputs array, begin , mid, and end
void merge(int arr[], int begin, int mid, int end)
{
	//Initialize temp array with current array values
	int arrTemp[12];
	for(int i = 0; i < 12; i++)
	{
	arrTemp[i] = arr[i];
	}
	//Initialize i to the left side of array and j to beginning of right side
	//tempi starts from the beginning
	int i = begin;
	int j = (mid+1);
	int tempi = begin;
	int k = 0;
	//Loop from beginning of subarrays to end of subarrays like left side and right side
	while(i <= mid && j <= end)
	{
		//Checks if the left side beginning is less than right side beginning
		//If yes, adds the left side value to temp array
		if(arr[i] < arr[j])
		{
			arrTemp[tempi] = arr[i];
			tempi++;
			i++;
		}
		//If left side beginning is larger than the right side
		//add the right side value to the temp array
		else if(arr[i] >= arr[j])
		{
			arrTemp[tempi] = arr[j];
			tempi++;
			j++;
		}
	}
	//add the rest of the values in the left side array to the temp array
	while (i <= mid)
	{
		arrTemp[tempi] = arr[i];
		tempi++;
		i++;
	}
	//adds the rest of the values in the right side array to temp array
	while (j <= end)
	{
		arrTemp[tempi] = arr[j];
		tempi++;
		j++;
	}
	//Loops from 0 to the end of the array. 
	//Adds the sorted array from the temp array to the given array
	while(k < (end+1))
	{
		arr[k] = arrTemp[k];
		k++;
	}
}
