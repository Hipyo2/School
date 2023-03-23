//Project 8
//Nicholas Ang
//Array List Source file

#include <header/ArrayList.h>
#include <iostream>
using namespace std;

//Default Constructor - values set to Null/0
ArrayList::ArrayList()
{
	m_array = NULL;
	m_size = 0;
	m_maxsize = 0;
}

//Parameterized Constructor - values set to datatype
ArrayList::ArrayList(size_t count, const DataType &value)
{
	size_t i = 0;
	m_size = count;
	m_maxsize = count;
	m_array = new DataType[count];

	//Sets every part of array
	while(i<count)
	{
	m_array[i] = value;
	i++;
	}

}

//Copy Constructor
ArrayList::ArrayList(const ArrayList &other)
{
	//Sets size to other size
	size_t i = 0;
	m_size = other.m_size;
	m_maxsize = other.m_maxsize;
	m_array = new DataType[other.m_maxsize];

	//Sets values of other array
	while(i<m_maxsize)
	{
	m_array[i] = other.m_array[i];
	i++;
	}
}

//Destructor - delete every part in array
ArrayList::~ArrayList()
{
delete [] m_array;
}

//Operator Overload for assignment
//Similar to copy constructor
ArrayList &ArrayList::operator=(const ArrayList &rhs)
{
	//Check for self assignment
	if(this != &rhs)
	{
		//Cleans array first
		delete [] m_array;
		m_array = new DataType[rhs.m_maxsize];
		//Assigns values of rhs to the array
		m_size = rhs.m_size;
		m_maxsize = rhs.m_maxsize;
		size_t i = 0;
		//Increments and loops through each part of array
		while(i<m_maxsize)
		{
			m_array[i] = rhs.m_array[i];
			i++;
		}
	}
	return *this;
}

//Gets the first part of the array if the array is valid
DataType *ArrayList::front()
{
	if(m_array != NULL)
	{
		return &m_array[0];
	}
	else
	{
		return NULL;
	}

}

//Gets the last part of array if valid
DataType *ArrayList::back()
{
	if(m_array != NULL)
	{
		return &m_array[m_size-1];
	}
	else
	{
		return NULL;
	}
}

//Find function to find the targeted Datatype
DataType *ArrayList::find(const DataType &target, DataType* &previous, const DataType *after)
{
	size_t i = 0;
	//Checks if invalid
	if(m_array == NULL)
	{
		previous = NULL;
		return NULL;
	}
	//Sets it to the front or where it needs to start
	DataType *array = after == NULL ? &m_array[0] : const_cast <DataType *>(after);
	//finds array, if found return it
	while (i<m_size)
	{
		if(array[i] == target)
		{
			//check if it is first, otherwise has previous array sections
			if (i == 0)
			{
				return &array[i];
			}
			else
			{
				previous = &array[i-1];
				return &array[i];
			}
			i++;
		}
	}
	//If nothing found, return null values
	previous = NULL;
	return NULL;
}

//Inserts new datatype into selected spot after the target
DataType *ArrayList::insertAfter(const DataType &target, const DataType &value)
{
	//Resizes it to accomodate new datatype
	resize(m_size+1);
	size_t i = 1;
	DataType *prevarray = NULL;
	//Finds target
	DataType *targetValue = find(target,prevarray);
	DataType *back = this->back();
	//Checks for Null targets
	if(targetValue == nullptr)
	{
		return NULL;
	}

	if(back == nullptr)
	{
		return NULL;
	}
	m_size++;
	//Replaces the values and puts them one place over to fit new data
	DataType numArr = value;
	while (&targetValue[i] <= back+1)
	{
		DataType temp = targetValue[i];
		targetValue[i] = value;
		numArr = temp;
		i++;
	}
	//returns after the target - correct one
	return targetValue + 1;
}

//Inserts New datatype before the target, one space behind
DataType *ArrayList::insertBefore(const DataType &target, const DataType &value)
{
	//Resizes to accomodate new
	resize(m_size+1);
	size_t i = 0;
	DataType *prevarray = NULL;
	DataType *targetValue = find(target,prevarray);
	//Checks for Null targets
	if(targetValue == nullptr)
	{
		return NULL;
	}
	DataType *back = this->back();
	if(back == nullptr)
	{
		return NULL;
	}
	m_size++;
	DataType numArr = value;
	//Iterates over the values and copies it over to fit new data
	while (&targetValue[i] <= back)
	{
		DataType temp = targetValue[i];
		targetValue[i] = value;
		numArr = temp;
		i++;
	}
	//returns where the object is currently is, since original target was moved over 1.
	return targetValue;
}

//Erase a target from existence - obliterates the target
DataType *ArrayList::erase(const DataType &target)
{
	size_t i = 0;
	DataType *prevarray = NULL;
	DataType *targetValue = find(target,prevarray);
	//Checks if target is not valid in the first place
	if(targetValue == NULL)
	{
		return NULL;
	}
	DataType *back = this->back();
	//Moves the objects over by one
	while(&targetValue[i] < back)
	{
		targetValue[i] = targetValue[i+1];
		i++;
	}
	//Resizes to stop accomodation of the target
	resize(m_size-1);
	m_size--;
	//if the target is not the back value, return invalid 
	if(targetValue != back)
	{
		return NULL;
	}
	//Otherwise return Target
	else
	{
		return targetValue;
	}

}

//Returns position with operator overload for []
DataType &ArrayList::operator[] (size_t position)
{
	return m_array[position];
}

//gets the size of the valid entries in the array
size_t ArrayList::size() const
{
	return m_size;
}

//Checks if everything is gone from the array
bool ArrayList::empty() const
{
	if (m_size == 0)
	{
	return true;
	}
	else
	{
	return false;
	}
}

//Removes Everything from the Array, resets everything
void ArrayList::clear()
{
	delete [] m_array;
	m_array = NULL;
	m_size = 0;
	m_maxsize = 0;
}

//Operator Overload for <<
//Prints out everything in the arraylist
std::ostream &operator<<(std::ostream &os, const ArrayList &arrayList)
{
	size_t i = 0;
	while(i< arrayList.size())
	{
		os << arrayList.m_array[i];
		i++;
	}
	return os;
}

//Resizes the array to account for new accomodations/entries
void ArrayList::resize(size_t count)
{
	//Sets new array with values of array
	DataType *newsize = new DataType[count];
	//If count is greater than m_size, add everything from old array to new, set valid number to old valid number
	if(count > m_size)
	{
		for(size_t i = 0; i < m_size; i++)
		{
			newsize[i] = m_array[i];
		}
		m_size = m_size;
	}
	//If count is less that m_size, add everything from old array to new, set m_size to count
	else if (count < m_size)
	{
		for(size_t i = 0; i<count; i++)
		{
			newsize[i] = m_array[i];
		}
		m_size = count;
	}
	m_maxsize = count;
	//delete old array and set/point it to new one.
	delete m_array;
	m_array = newsize;
}

