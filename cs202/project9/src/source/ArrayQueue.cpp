//Project 9
//Nicholas Ang
//Array Queue Source file and implementation

//Libraries and Header Files
#include <iostream>
#include <header/ArrayQueue.h>
#include <header/DataType.h>
using namespace std;

//Operator Overload for <<
std::ostream &operator<<(std::ostream &os, const ArrayQueue &arrayQueue)
{
	//Calls Serialize function then outputs it to terminal
	arrayQueue.serialize(os);
	return os;
}

//Default Constructor for Array Queue
ArrayQueue::ArrayQueue()
{
	//Sets all values to 0
	m_front = 0;
	m_back = 0;
	m_size = 0;
}

//Parameterized Constructor for Array Queue
ArrayQueue::ArrayQueue(size_t count, const DataType &value)
{
	//Sets front to 0 and back to wherever the count is, unless count is greater than max value.
	size_t i = 0;
	m_front = 0;
	//Compares count to max value and sets size and m_back appropriately
	if(count > ARRAY_CAPACITY)
	{
		m_size = ARRAY_CAPACITY;
		m_back = ARRAY_CAPACITY-1;
		}
	else
	{
		m_size = count;
		m_back = count-1;
	}
	//Sets every element in array queue to value
	while(i<m_size)
	{
		m_array[i] = value;
		i++;
	}
}

//Copy Constructor for Array Queue
ArrayQueue::ArrayQueue(const ArrayQueue &other)
{
	//Sets Values of Array Queue to other front, size, and back
	size_t i = 0;
	m_front = other.m_front;
	m_back = other.m_back;
	m_size = other.m_size;
	//Sets the data inside array queue to other array queue
	while(i < m_size)
	{
		m_array[i] = other.m_array[i];
		i++;
	}
}

//Destructor of Array Queue - clears queue before destructing
ArrayQueue::~ArrayQueue()
{
	clear();
}

//Assignment Operator for =
ArrayQueue &ArrayQueue::operator=(const ArrayQueue &rhs)
{
	//Checks for self Assignment
	if(this != &rhs)
	{
		//Clears the array queue, then sets values of rhs to assigned queue
		clear();
		m_size = rhs.m_size;
		m_front = rhs.m_front;
		m_back = rhs.m_back;
		//Copys values from rhs to assigned
		for(size_t i = m_front; i < m_size; i++)
		{
			m_array[i] = rhs.m_array[i];
		}
	}
	//Returns Assigned Array Queue
	return *this;
}

//Front Function - returns array at the first element/front of the queue
DataType &ArrayQueue::front()
{
	return m_array[m_front];
}

//Front Function - Const version, similar functionality to above Front function
const DataType &ArrayQueue::front() const
{
	return m_array[m_front];
}

//Back Function - returns array at the point of m_back
DataType &ArrayQueue::back()
{
	return m_array[m_back];
}

//Back Function - Const version, similar functionality to above back function
const DataType &ArrayQueue::back() const
{
	return m_array[m_back];
}

//Array Queue Pushing Method
void ArrayQueue::push(const DataType &value)
{	
	//Checks if full. If full, do nothing
	if(full())
	{
	}
	//Else add an element to the back and instantiate it with value. Also increase size to accomodate
	else
	{
		m_back = (m_back+1) % ARRAY_CAPACITY;
		m_array[m_back] = value;
		m_size++;
	}
}

//Array Queue popping method
void ArrayQueue::pop()
{
	//Checks if empty first
	if(empty())
	{
	}
	//Deletes the front element of the Queue and change size
	else
	{
		m_front = (m_front+1) % ARRAY_CAPACITY;
		m_size--;
	}
}

//Size Function - Getter - returns size of queue
size_t ArrayQueue::size() const
{
	return m_size;
}

//Empty Function to check if queue is empty
bool ArrayQueue::empty() const
{
	//Checks if amount of valid objects is 0, if yes, return true. if no, return false
	if(m_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Full Function to check if queue is full
bool ArrayQueue::full() const
{
	//Checks if the amount of valid objects inside Queue is the same as Array Capacity
	//If same, queue is full
	if(m_size == ARRAY_CAPACITY)
	{
		return true;
	}
	//else, queue is not full
	else
	{
		return false;
	}
}

//Clear Function, sets values to 0
void ArrayQueue::clear()
{
	m_front = 0;
	m_back = 0;
	m_size = 0;
}

//ArrayQueue Serialize Function to print out Queues
void ArrayQueue::serialize(std::ostream &os) const
{
	size_t i = m_front;
	//Checks if Queue has anything in the first place
	if(m_size > 0)
	{
		//Checks and Prints out the array until it reaches the back of the Queue
		while(i <= m_back)
		{
			os << m_array[i] << " ";
			i++;
		}
	}
}
