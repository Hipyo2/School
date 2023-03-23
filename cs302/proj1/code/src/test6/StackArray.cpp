
#include <iostream>
#include "Stack.h"
#include "StackArray.h"
#include <stdexcept>


using namespace std;

//Default constructor - Allocates enough memory for a stack containing Max Size dataItems
template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber)
{
	top = -1;
	maxSize = maxNumber;
	dataItems = new DataType[maxSize];
}

//Copy Constructor - copies the data of another stack and constructs a new stack with that data
template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)
{
	int i = 0;
	//Sets new Stack to top and maxSize values of other Stack
	top = other.top;
	maxSize = other.maxSize;
	while (i < top)
	{
		//Copies data values from other Stack to new Stack
		dataItems [i] = other.dataItems[i];
		i++;
	}
}

//Assignment Operator Overload - copies values of one stack to another
template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other)
{
	int i = 0;
	//Checks for self-assignment
	if(this != other)
	{
		//Deallocates Stack Array
		delete dataItems;

		//Copies top and maxSize values 
		maxSize = other.maxSize;
		top = other.top;

		//Reallocates Stack array
		dataItems = new DataType[maxSize];

		while(i < top)
		{
			//Copies Data from other Stack
			dataItems[i] = other.dataItems[i];
			i++;
		}
	}
	return this;
}

//Destructor - deallocates memory of dataItems stack array
template <typename DataType>
StackArray<DataType>::~StackArray()
{
	delete [] dataItems;
}

//Push function - adds another item to top of stack
template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
	//Checks if full and throws out error message if full
	if(isFull())
	{
		throw logic_error("Stack is full, Cannot Push onto Stack.");
	}
	//Otherwise, add new item to the top and increase the top size
	else
	{
		top++;
		dataItems[top] = newDataItem;
	}
}

//Pop Function - removes and returns top item from stack array
template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)
{
	//Checks if empty and throws out error message if there is nothing to pop
	if(isEmpty())
	{
		throw logic_error("Stack is Empty, Cannot Pop from Stack.");
	}
	//Return top item
	else
	{
		return dataItems[top--];
	}
}

//Set top to value -1 to effectively clear array as the data is unaccessable
template <typename DataType>
void StackArray<DataType>::clear()
{
	top = -1;
}

//isEmpty function - checks if the top is a negative value and holds nothing in stack array
template <typename DataType>
bool StackArray<DataType>::isEmpty() const
{
	return top == -1;
}

//isFull function - checks if the top is at the maxSize - 1 due to array starting at 0
template <typename DataType>
bool StackArray<DataType>::isFull() const
{
	return top == maxSize - 1;
}


//Given Show Structure Function code 
template <typename DataType>
void StackArray<DataType>::showStructure() const 

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    if( isEmpty() ) {
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "Top = " << top << endl;
	for ( j = 0 ; j < maxSize ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
}
