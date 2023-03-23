//Project 9
//Nicholas Ang
//Array Queue Class Declaration Header File

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

//Libraries and Header Files
#include <iostream>
#include <header/DataType.h>
using namespace std;

//Global Variables
const size_t ARRAY_CAPACITY = 1000;

//Class Declaration of Array Queue
class ArrayQueue
{
	//Operator Overload for <<
	friend std::ostream &operator<<(std::ostream &os, const ArrayQueue &arrayQueue);

	//Public Methods and Members
	public:
		//Constructors
		ArrayQueue();
		ArrayQueue(size_t count, const DataType &value);
		ArrayQueue(const ArrayQueue &other);
		~ArrayQueue();

		//Operator overload for = assignment
		ArrayQueue &operator=(const ArrayQueue &rhs);

		//Front and Back Functions
		DataType &front();
		const DataType &front() const;

		DataType &back();
		const DataType &back() const;
		//Push and Pop methods for queue adding and deleting
		void push(const DataType &value);
		void pop();

		//Size,Empty,Full functions
		size_t size() const;
		bool empty() const;
		bool full() const;
		//Clear Function to delete and reset object
		void clear();
		//Serialize Method
		void serialize(std::ostream &os) const;

	//Private Methods and Members
	private:
		DataType m_array[ARRAY_CAPACITY];
		size_t m_front;
		size_t m_back;
		size_t m_size;


};


#endif /* ARRAYQUEUE_H */
