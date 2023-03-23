//Project 10
//Nicholas Ang
//NodeStack HPP file


#ifndef NODESTACK_HPP
#define NODESTACK_HPP

//Libraries and HPP files
#include <NodeStack/Node.hpp>
#include <iostream>
using namespace std;

//Template Forward Declaration
template <typename T>
class NodeStack;

//Template Declaration of Operation Overload <<
template <typename T>
std::ostream &operator<<(std::ostream &os, const NodeStack<T> &nodeStack);

//Template NodeStack class
template <typename T>
class NodeStack
{
	//Operator overload for << - calls Serialize function to output data
	friend std::ostream &operator<<(std::ostream &os, const NodeStack <T> &nodeStack)
	{
		nodeStack.serialize(os);
		return os;
	}

	//Public Methods and Members
	public:
		NodeStack();
		NodeStack(size_t count, const T &value);
		NodeStack(const NodeStack<T> &other);
		~NodeStack();

		NodeStack<T> &operator=(const NodeStack<T> &rhs);
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
		Node<T> *m_top;
};

//Default Constructor
template <typename T>
NodeStack<T>::NodeStack()
{
	//Sets m_top to null values
	m_top = nullptr;
}

//Parameterized Constructor
template <typename T>
NodeStack<T>::NodeStack(size_t count, const T &value)
{
	//m_top is set to nullptr
	m_top = nullptr;
	size_t i = 0;
	//Pushes new nodes into stack up to count
	while(i < count)
	{
		push(value);
		i++;
	}
}

//Copy Constructor
template <typename T>
NodeStack<T>::NodeStack(const NodeStack<T> &other)
{
	//Sets the top to nullptr
	m_top = nullptr;
	//Checks if the other stack top is null, if not
	if(other.m_top != NULL)
	{
		//Set node from other to new node, set top to the node
		Node<T> *node = new Node<T>(other.m_top->m_data);
		m_top = node;
		Node<T> *newNode = other.m_top->m_next;
		//Create new nodes and link to each other using values from other
		while (newNode != NULL)
		{
			node->m_next = new Node<T>(newNode->m_data);
			newNode = newNode->m_next;
			node = node->m_next;
		}
	}
}

//Destructor - calls clear function
template <typename T>
NodeStack<T>::~NodeStack()
{
	clear();
}

//Operator overload for assignment operator =, similar to copy constructor
template <typename T>
NodeStack<T> &NodeStack<T>::operator=(const NodeStack<T> &rhs)
{
	//Initially clear the stack
	clear();
	//Check for self assignment
	if(this != &rhs)
	{
		//Checks if the top is null, sets new node to top
		if(rhs.m_top != NULL)
		{
			Node<T> *node = new Node<T>(rhs.m_top->m_data);
			m_top = node;
			Node<T> *newNode = rhs.m_top->m_next;
			//Copies and creates new nodes in the stack
			while (newNode != NULL)
			{
				node->m_next = new Node<T>(newNode->m_data);
				newNode = newNode->m_next;
				node = node->m_next;
			}
		}
	}
	//returns stack
	return *this;
}

//Top Function - returns top node's data
template <typename T>
T &NodeStack<T>::top()
{
	return m_top->m_data;
}

//Top Function - returns top Node's data - const version
template <typename T>
const T &NodeStack<T>::top() const
{
	return m_top->m_data;
}

//Push Function
template <typename T>
void NodeStack<T>::push(const T &value)
{
	//Checks if the object has no nodes inside
	if(m_top == NULL)
	{
		m_top = new Node<T>(value);
	}
	//otherwise, create and set new node as the top of the stack
	else
	{
		Node<T> *top = m_top;
		m_top = new Node<T>(value);
		m_top->m_next = top;
	}
}

//Pop function
template <typename T>
void NodeStack<T>::pop()
{
	//Checks if the node stack is empty, does nothing if yes
	if(m_top == NULL)
	{
		return;
	}
	//Otherwise delete the topmost node in the stack
	else
	{
		Node<T> *top = m_top;
		m_top = m_top->m_next;
		delete top;
	}
}

//Size function
template <typename T>
size_t NodeStack<T>::size() const
{
	//Iterates from the top to bottom, counter increases for each node element
	size_t i = 0;
	Node<T> *node = m_top;
	while(node != NULL)
	{
		node = node->m_next;
		i++;
	}
	node = nullptr;
	//returns counter
	return i;
}

//Empty function
template <typename T>
bool NodeStack<T>::empty() const
{
	//Checks if there is nothing left, if m_top = nullptr, returns true
	if(m_top == nullptr)
	{
		return true;
	}
	//otherwise returns false
	else
	{
		return false;
	}
}

//Full Function
template <typename T>
bool NodeStack<T>::full() const
{
	//Always return false
	return false;
}

//Clear function - deletes everything in stack
template <typename T>
void NodeStack<T>::clear()
{
	//Loops and calls pop function
	while(empty() == false)
	{
		pop();
	}
}

//Serialize Function
template <typename T>
void NodeStack<T>::serialize(std::ostream &os) const
{
	//Loops until the program finds invalid node
	Node<T> *node = m_top;
	while(node != NULL)
	{
		//Outputs data to os
		os << node->m_data << " ";
		node = node->m_next;
	}
}
#endif /* NODESTACK_HPP */
