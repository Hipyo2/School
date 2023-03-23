//Project X
//Nicholas Ang
//Smart Pointer Source File

#include <SmartPtr/SmartPtr.h>
#include <iostream>
using namespace std;

//Default Constructor of SmartPtr
SmartPtr::SmartPtr()
{
	//Allocates Dynamic memory and sets the dereferenced pointer to the value of 1
	int i = 1;
	m_ptr = new DataType;
	m_refcount= new size_t;
	*m_refcount = i;

	//Debugger Message, says the refcount
	cout << "SmartPtr Default Constructor for new allocation, RefCount = " << *m_refcount << endl;

}

//Parameterized Constructor of SmartPtr
SmartPtr::SmartPtr(DataType *data)
{
	//Sets pointer to the pointer of data
	m_ptr = data;
	m_refcount = new size_t;
	//Checks for nullptr, if not nullptr, set refcount to 1
	if(data != nullptr)
	{
		*m_refcount = 1;
	}
	//Else set refcount to 0
	else if(data == nullptr)
	{
		*m_refcount = 0;
	}

	//Debugger Message, says refcount
	cout << "SmartPtr Parameterized Constructor from data pointer, RefCount = " << *m_refcount << endl;
}

//Copy Constructor of SmartPtr
SmartPtr::SmartPtr(const SmartPtr &other)
{
	//Checks if the pointer of the other smartptr is a null ptr
	//if not, set values of other smartptr to this object
	if(other.m_ptr != nullptr)
	{
		m_refcount = other.m_refcount;
		(*m_refcount)++;
		m_ptr = other.m_ptr;
	}
	//else set pointer to other ptr (nullptr) and set refcount to 0
	else
	{
		m_refcount = new size_t;
		*m_refcount = 0;
		m_ptr = other.m_ptr;
	}

	//debugger message, says refcount
	cout << "SmartPtr Copy Constructor, RefCount = " << *m_refcount << endl;
}

//Destructor of SmartPtr
SmartPtr::~SmartPtr()
{
	//Checks if it is last of its kind, if not decrements refcount
	if(*m_refcount !=0)
	{
		(*m_refcount)--;
	}

	//debugger message, says refcount after decrements
	cout << "SmartPtr Destructor, RefCount = " << *m_refcount << endl;
	//Deletes ptr and refcount to free up dynamic memory if refcount is 0
	if(*m_refcount == 0)
	{
		delete m_ptr;
		delete m_refcount;
		m_ptr = NULL;
		m_refcount = NULL;
	}

}

//Operator Overload = for assigning values of one smart pointer to another
SmartPtr &SmartPtr::operator=(const SmartPtr &rhs)
{
	//Checks for self assignment
	if(this != &rhs)
	{
		//Resets the smart pointers if valid
		if(*m_refcount !=0)
		{
			(*m_refcount)--;
		}
		if(*m_refcount == 0)
		{
			delete m_ptr;
			delete m_refcount;
			m_ptr = NULL;
			m_refcount = NULL;
		}

		//Checks values of rhs if it does not point to a nullptr
		if(rhs.m_ptr != nullptr)
		{
			//Sets values of rhs to expected object
			m_ptr = rhs.m_ptr;
			m_refcount = rhs.m_refcount;
			(*m_refcount)++;
		}
		//If rhs is pointing to nullptr
		else
		{
			//Sets pointer to rhs pointer and sets refcount to 0
			m_ptr = rhs.m_ptr;
			delete m_refcount;
			m_refcount = new size_t;
			*m_refcount = 0;
		}

	}

	//Debugger message, says refcount
	cout << "SmartPtr Copy Assignment, RefCount = " << *m_refcount << endl;
	return *this;
}

//Operator Overload * for Dereferencing
DataType &SmartPtr::operator*()
{
	return *m_ptr;
}

//Operator Overload -> for Member Access
DataType *SmartPtr::operator->()
{
	return m_ptr;
}




