#include <iostream>
#include <stdexcept>
#include "Stack.h"
#include "StackLinked.h"

using namespace std;

template<typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType &nodeData, StackNode *nextPtr)
{
	dataItem = nodeData;
	next = nextPtr;
}

//Default constructor - sets top to null since nothing is supposed to be inside
template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber)
{
	top = nullptr;
}

//Copy constructor - copies Stack to create new Stack
template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
	//Sets top to null before setting it to an actual pointer
	top = nullptr;
	//Checks if other stack is valid
	if(other.top != nullptr)
	{
		//Sets new node to top, same value as other top
		StackNode *node = new StackNode(other.top->dataItem);
		top = node;
		StackNode nextNode = other.top->next;
		//copies and creates new nodes in the stack
		while(nextNode != nullptr)
		{
			node->next = new StackNode(nextNode->dataItem);
			nextNode = nextNode->next;
			node = node->next;
		}
	}
}

//Assignment Operator overload - copies one linked list to another
template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
	//checks for self assignment
	if(this != other)
	{
		//clears entire stack to ensure nothing is inside
		clear();
		//Checks if other stack is valid
		if(other.top != nullptr)
		{
			//Creates new node as the same as other top and sets it as top
			StackNode *node = new StackNode(other.top->dataItem);
			top = node;
			StackNode nextNode = other.top->next;
			//Copies and creates new nodes in the stack
			while(nextNode != nullptr)
			{
				node->next = new StackNode(nextNode->dataItem);
				nextNode = nextNode->next;
				node = node->next;
			}
		}
	}
	return *this;
}

//Destructor - calls clear function to clear entire stack and destroys stack
template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
	clear();
}

//Push function - adds new node to top of stack
template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
	//Impossible to be full, so no error will ever happen
	if(isFull())
	{
		throw logic_error ("Stack is full, Cannot Push onto Stack");
	}

	//Checks if empty to establish new top node
	if(isEmpty())
	{
		top = new StackNode(newDataItem, top);
	}
	//If not empty, sets new node to new top and links nodes
	else
	{
		StackNode *node = top;
		top = new StackNode(newDataItem, top);
		top->next = node;
	}
}

//Pop function - returns node data and removes Node from top
template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
	//Checks if empty and throws error message if true
	if(isEmpty())
	{
		throw logic_error("Stack is empty, Cannot Pop from Stack.");
	}
	//Otherwise, remove top and return its data
	else
	{
		DataType nodeData = top->dataItem;
		StackNode *nodeTop = top;
		top = top->next;
		delete nodeTop;
		return nodeData;
	}
}

//Clear function - Pops all values until empty
template <typename DataType>
void StackLinked<DataType>::clear()
{
	while(isEmpty() == false)
	{
		pop();
	}
}

//isEmpty function - checks if the top is pointing to null which indicates nothing is in Stack
template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
	return top == nullptr;
}

//isFull function - always return false due to being unable to reach a Max Size
template <typename DataType>
bool StackLinked<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const 

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << "[" << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }

}

