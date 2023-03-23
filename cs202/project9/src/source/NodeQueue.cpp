//Project 9
//Nicholas Ang
//Node Queue Implementation and source file

//Libraries and Header files
#include <iostream>
#include <header/NodeQueue.h>
#include <header/DataType.h>
using namespace std;

//Operator overload for << - calls serialize function to output to terminal
std::ostream &operator<<(std::ostream &os, const NodeQueue &nodeQueue)
{
	nodeQueue.serialize(os);
	return os;
}

//Default Constructor - all values NULL
NodeQueue::NodeQueue()
{
	m_front = NULL;
	m_back = NULL;
}

//Parameterized Constructor
NodeQueue::NodeQueue(size_t size, const DataType &value)
{
	//Creates initial node head
	m_front = new Node(value);
	size_t i = 0;
	Node *node = m_front;
	//Sets the next node and every node after to value
	while(i< (size-1))
	{
		node->m_next = new Node(value);
		node = node->m_next;
		i++;
	}
	//Sets m_back to the end of the Queue
	m_back = node;
}

//Copy Constructor for Node Queue
NodeQueue::NodeQueue(const NodeQueue &other)
{
	//Checks if the other node queue is empty and has no valid values
	//Sets new node queue to null values
	if(other.m_front == nullptr)
	{
		m_front = NULL;
		m_back = NULL;
	}
	//Sets initial node head to other m_front
	m_front = new Node(*other.m_front);
	Node *othernode = other.m_front->m_next;
	Node *node = m_front;
	//Sets each next node to the other and copies it over, dynamically allocating a new node for the queue
	while(othernode != nullptr)
	{
		node->m_next = othernode->m_next;
		node->m_next = new Node(*othernode);
		node = node->m_next;
		othernode = othernode->m_next;
	}
	//Sets m_back to end of queue
	m_back = node;
}

//Destructor for Node Queue - calls clear function before destroying object
NodeQueue::~NodeQueue()
{
	clear();
}

//Operator overload for = 
NodeQueue &NodeQueue::operator=(const NodeQueue &rhs)
{
	//clears the queue so its empty
	clear();
	//Checks for self assignment
	if(this != &rhs)
	{
		//checks if rhs is not valid - sets value to null
		if(rhs.m_front == nullptr)
		{
			m_front = NULL;
			m_back = NULL;
		}
		//sets head of node to rhs.m_front
		m_front = new Node(*rhs.m_front);
		Node *rhsnode = rhs.m_front->m_next;
		Node *node = m_front;
		//dynamically allocates and copies over values
		while(rhsnode != nullptr)
		{
			node->m_next = rhsnode->m_next;
			node = node->m_next;
			rhsnode = rhsnode->m_next;
		}
		//sets m_back to end of queue
		m_back = node;
	}
	return *this;
}

//Returns the data of m_front
DataType &NodeQueue::front()
{
	return m_front->data();
}

//Returns the data of m_front - const version
const DataType &NodeQueue::front() const
{
	return m_front->data();
}

//Returns the data of m_back
DataType &NodeQueue::back()
{
	return m_back->data();
}

//Returns the data of m_back - const version
const DataType &NodeQueue::back() const
{
	return m_back->data();
}

//Push function - Pushes and adds new element to the back of the queue
void NodeQueue::push(const DataType &value)
{
	//Creates a new node with given value
	Node *newNode = new Node(value);
	//checks if m_back is an actual node instead of null
	//if null, set the new node as the only one of its kind in the array
	if(m_back == NULL)
	{
		m_back = newNode;
		m_front = newNode;
	}
	//otherwise push the object normally
	else
	{
		m_back->m_next = newNode;
		m_back = newNode;
	}
}

//Pop function - deletes front most node
void NodeQueue::pop()
{
	//checks if empty first, if yes - set to null values
	if(empty() == true)
	{
		m_front = NULL;
		m_back = NULL;
	}
	//Delete the front most node
	Node *newNode = m_front;
	m_front = m_front->m_next;
	delete (newNode);
}

//Size function to return size of node queue
size_t NodeQueue::size() const
{
	Node *node = m_front;
	size_t i = 0;
	//iterates through every node until it reaches back
	while(node != NULL)
	{
		node = node->m_next;
		i++;
	}
	return i;
}

//Checks if queue is empty and has no valid nodes
bool NodeQueue::empty() const
{
	if(size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Can never be true as it can continually be dynamically allocated
bool NodeQueue::full() const
{
	return false;
}

//Clear function - deletes every node in queue
void NodeQueue::clear()
{
	Node *node = m_front;
	Node *temp = NULL;
	//iterates through every node and deletes it
	while(node != NULL)
	{
		temp = node;
		node = node->m_next;
		delete temp;
	}
	//sets queue to null values
	m_front = NULL;
	m_back = NULL;
}

//Serialize Function to Output 
void NodeQueue::serialize(std::ostream &os) const
{
	Node *node = m_front;
	//iterates through every node and outputs its data
	while(node != NULL)
	{
		os << node->data() << " ";
		node = node->m_next;
	}
}
