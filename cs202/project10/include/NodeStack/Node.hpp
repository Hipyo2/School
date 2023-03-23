//Project 10
//Nicholas Ang
//Node HPP file

#ifndef NODE_HPP
#define NODE_HPP

//Libraries and Header Files
#include <NodeStack/NodeStack.hpp>
#include <iostream>
using namespace std;

//Template Forward Declaration
template <typename T> 
class Node;

//Template Declaration of class Nodestack
template <typename> class NodeStack;

//Template Class Node
template <typename T>
class Node
{	
	//Friend class nodestack for node use
	friend class NodeStack <T>;
	//Public Members and Methods
	public:
		Node();
		Node(const T &data, Node<T> *next = nullptr);

		T &data();
	const T &data() const;
	//Private Methods and Members
	private:
		Node *m_next;
		T m_data;
};

//Template implementation
//Node Default Constructor
template <typename T>
Node<T>::Node() : m_next(nullptr)
{
}

//Node Parameterized Constructor
template <typename T>
Node<T>::Node(const T &data, Node<T> *next) : m_next(next)
{
	m_data = data;
}

//Data Function - returns m_data
template <typename T>
T &Node<T>::data()
{
	return m_data;
}

//Data Function - returns m_data - const version
template <typename T>
const T &Node<T>::data() const
{
	return m_data;
}










#endif /* NODE */
