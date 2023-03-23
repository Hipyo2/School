//Project 10
//Nicholas Ang
//Array Stack HPP file

#ifndef ARRAYSTACK_HPP
#define ARRAYSTACK_HPP

//Libraries and HPP files
#include <iostream>
using namespace std;

//Global Variables
const size_t ARRAY_CAPACITY = 1000;

//Template Forward Declaration
template <typename T>
class ArrayStack;

//Declaration of Operator overload << 
template <typename T>
std::ostream &operator<<(std::ostream &os, const ArrayStack<T> &arrayStack);


//Template Class
template <typename T>
class ArrayStack
{
	
	//Operator overload for <<
	//Calls Serialize function to output to terminal
	friend std::ostream &operator<<(std::ostream &os, const ArrayStack <T> &arrayStack)
	{
		arrayStack.serialize(os);
		return os;
	}

	//Public Methods and Members
	public:
		ArrayStack();
		ArrayStack(size_t count, const T &value);
		ArrayStack(const ArrayStack<T> &other);
		~ArrayStack();
		ArrayStack<T> &operator= (const ArrayStack<T> &rhs);
		T &top();
		const T &top() const;

		void push(const T &value);
		void pop();
		size_t size() const;
		bool empty() const;
		bool full() const;
		void clear();
		void serialize(std::ostream &os) const;

	//Private Methods and Members
	private:
		T m_container[ARRAY_CAPACITY];
		size_t m_top;
};


//Template Implementations
//Default Constructor - sets top of the array as 0
template<typename T>
ArrayStack<T>::ArrayStack()
{
	m_top = 0;
}

//Parameterized Constructor
template<typename T>
ArrayStack<T>::ArrayStack(size_t count, const T &value)
{
	//Sets every element in array to value up to count
	size_t i = 0;
	//Checks if count is higher than array max size
	if(count > ARRAY_CAPACITY)	
	{
	//if greater, set m_top to max size
	m_top = ARRAY_CAPACITY;
	while(i<m_top)
	{
		m_container[i] = value;
		i++;
	}
	}
	else
	{
	//else set m_top to count
	m_top = count;
	while(i<m_top)
	{
		m_container[i] = value;
		i++;
	}
	}
}

//Copy Constructor
template<typename T>
ArrayStack<T>::ArrayStack(const ArrayStack &other)
{
	//Sets other stack values to new stack values
	m_top = other.m_top;
	size_t i = 0;
	while(i<m_top)
	{
		//copies every element
		m_container[i] = other.m_container[i];
		i++;
	}
}

//Destructor
template<typename T>
ArrayStack<T>::~ArrayStack()
{
	//Clear the array before destructing
	clear();
}

//Operator overload for assignment operator =
template<typename T>
ArrayStack<T> &ArrayStack<T>::operator=(const ArrayStack<T> &rhs)
{
	//Check for self assignment
	if (this != &rhs)
	{
		//Clear the stack first before copying every value
		clear();
		m_top = rhs.m_top;
		size_t i = 0;
		while(i<m_top)
		{
			//Copies all elements from rhs
			m_container[i] = rhs.m_container[i];
			i++;
		}
	}
	return *this;
}

//Returns the top of the array
template<typename T>
T &ArrayStack<T>::top()
{
	return m_container[m_top-1];
}

//Returns the top of the array - const version
template<typename T>
const T &ArrayStack<T>::top() const
{
	return m_container[m_top-1];
}

//Push function
template<typename T>
void ArrayStack<T>::push(const T &value)
{
	//Checks if the stack if full, does nothing if full
	if(full())
	{
		return;
	}
	//Otherwise add to the top
	else
	{
		m_container[m_top] = value;
		m_top++;
	}
}

//Pop Function
template<typename T>
void ArrayStack<T>::pop()
{
	//Checks if the stack is empty, does nothing if empty
	if(empty())
	{
		return;
	}
	//otherwise delete from the top
	else
	{
		m_top--;
	}
}

//Size function
//Returns the size of the array
template<typename T>
size_t ArrayStack<T>::size() const
{
	return m_top;
}

//Empty Function
template<typename T>
bool ArrayStack<T>::empty() const
{
	//Checks if the top is equal to 0, so empty - if yes return true
	if(m_top == 0)
	{
		return true;
	}
	//Otherwise return false
	else
	{
		return false;
	}
}

//Full Function
template<typename T>
bool ArrayStack<T>::full() const
{
	//Checks if the top is equal to the max size, if yes return true
	if(m_top == ARRAY_CAPACITY)
	{
		return true;
	}
	//Otherwise return false
	else
	{
		return false;
	}
}

//Clear Function
template<typename T>
void ArrayStack<T>::clear()
{
	//Sets m_top to 0
	m_top = 0;
}

//Serialize Function
template<typename T>
void ArrayStack<T>::serialize(std::ostream &os) const
{
	//Starts from the top to the bottom
	size_t i = m_top;
	//Subtracts from the top and outputs to os
	while(i > 1)
	{
		os << m_container[i-1] << " ";
		i--;
	}
	os << endl;
}
#endif /* ARRAYSTACK_HPP */
