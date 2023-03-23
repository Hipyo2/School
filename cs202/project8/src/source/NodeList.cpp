//Project 8 
//Nicholas Ang
//Node List Source File

#include <header/NodeList.h>
#include <iostream>
using namespace std;

//Node Default Constructor - head of link is null
NodeList::NodeList()
{
	m_head = NULL;
}

//Node Parameterized Constructor - sets node to values given
NodeList::NodeList(size_t count, const DataType &value)
{
	m_head = new Node(value);
	Node *head = m_head;
	//Sets chain for however many long is wanted
	for(size_t i = 1; i < count; i++)
	{
		head->m_next = new Node(value);
		head = head->m_next;
	}
}

//Copy Constructor for Nodes - sets node to values of other node
NodeList::NodeList(const NodeList &other)
{
	m_head = new Node(*other.m_head);
	Node *node = m_head;
	Node *othernode = other.m_head->m_next;
	//Links Nodes using the other node's values, checks until null value/end of chain
	while(othernode != NULL)
	{
		node->m_next = new Node(*othernode);
		node = node->m_next;
		othernode = othernode->m_next;
	}

}

//Destructor - uses clear method
NodeList::~NodeList()
{
	clear();
}

//Operator overload for =
NodeList &NodeList::operator=(const NodeList &rhs)
{
	//Checks for self-assignment
	if(this != &rhs)
	{
		//Sets values to everything rhs is
		m_head = new Node(*rhs.m_head);
		Node *node = m_head;
		Node *rhsnode = rhs.m_head->m_next;
		//Checks for null pointer, if not, assign stuff from rhs to wanted node
		while(rhsnode != NULL)
		{
		node->m_next = new Node(*rhsnode);
		node = node->m_next;
		rhsnode = rhsnode->m_next;
		}
	}
	return *this;
}

//Returns head of node link
Node *NodeList::front()
{
	return m_head;
}

//Returns back of Node links
Node *NodeList::back()
{
	Node *node = m_head;
	Node *endnode = NULL;
	//Finds the last node at the end
	while(node != NULL)
	{
	endnode = node;
	node = node->m_next;
	}
	return endnode;
}

//Find Function, finds where in the chain of nodes the target is
Node *NodeList::find(const DataType &target, Node *&previous, const Node *after)
{
	previous = NULL;
	Node *prevnode = NULL;
	//Sets it to where it starts or where the user wants it to start looking
	Node *node = after == NULL ? m_head : const_cast<Node *>(after);
	while(node != NULL)
	{
		prevnode = node;
		node = node->m_next;
		//checks if it matches data and returns the node
		if(node->m_data == target)
		{
			previous = prevnode;
			return node;
		}
	}
	//nothing found = nullptr return
	return nullptr;
}

//Inserts new node after the target
Node *NodeList::insertAfter(const DataType &target, const DataType &value)
{
	Node *prev = NULL;
	//Finds target and checks for Null Values
	Node *targetedNode = find(target, prev);
	if(targetedNode == NULL)
	{
		return nullptr;
	}
	//Sets the node after it the values and the targetednode->m_next to be the original next node
	Node *node = new Node(value);
	node->m_next = targetedNode->m_next;
	targetedNode->m_next = node;
	return node;
}

//Inserts node before the target
Node *NodeList::insertBefore(const DataType &target, const DataType &value)
{
	Node *prev = NULL;
	Node *targetedNode = find(target, prev);
	//Checks if target is not valid
	if(targetedNode == NULL)
	{
		return nullptr;
	}
	Node *node = new Node(value);
	//Checks if the target is the first in the chain then sets the new node behind the original head
	if(prev == NULL)
	{
		node->m_next = m_head->m_next;
		m_head->m_next = node;
	}
	//Otherwise act as normal and set it before the original
	else
	{
		node->m_next = prev->m_next;
		prev->m_next = node;
	}
	return node;
}

//Erases Node from existence 
Node *NodeList::erase(const DataType &target)
{
	Node *node = NULL;
	Node *prev = NULL;
	Node *targetedNode = find(target, prev);
	//Checks if target is invalid
	if(targetedNode == NULL)
	{
		return targetedNode;
	}
	//checks if it is the first node / is the head
	if(prev != NULL)
	{
		//If not head, everything is moved by 1
		prev->m_next = targetedNode->m_next;
		node = prev;
	}
	else if (prev == NULL)
	{
		//Otherwise set the next node to head
		m_head = targetedNode->m_next;
		node = m_head;
	}
	delete targetedNode;
	return node;
}

//Operator overload for []
DataType &NodeList::operator[] (size_t position)
{
	Node *node = m_head;
	size_t i = 0;
	//iterates through positions to find the right node
	for(i=0; i<position; i++)
	{
		node = node->m_next;
	}
	return node->m_data;
}

//Operator overload for [] (const version)
const DataType &NodeList::operator[] (size_t position) const
{
	Node *node = m_head;
	size_t i = 0;
	//Same thing as before but for const types
	for(i=0; i<position; i++)
	{
		node = node->m_next;
	}
	return node->m_data;
}

//Gets the size of the valid amount of Nodes
size_t NodeList::size() const
{
	Node *node = m_head;
	size_t i = 0;
	while (node != NULL)
	{
		node = node->m_next;
		i++;
	}
	return i;
}

//Checks if node list is empty
bool NodeList::empty() const
{
	if(m_head == NULL)
	{
	return true;
	}
	else 
	{
	return false;
	}
}

//Clears everything from Node list
void NodeList::clear()
{
	Node *nullnode = NULL;
	Node *node = m_head;
	//Deletes all valid nodes and sets the list head to nullptr
	while(node != NULL)
	{
		nullnode = node->m_next;
		delete node;
		node = nullnode;
	}

	m_head = NULL;
}

//Operator overload for <<
//Outputs every node in the list
std::ostream &operator<<(std::ostream &os, const NodeList &nodeList)
{
for(size_t i = 0; i<nodeList.size();i++)
{
os << nodeList[i] << endl;
}
return os;
}
