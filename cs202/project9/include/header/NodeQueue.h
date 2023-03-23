//Project 9
//Nicholas Ang
//NodeQueue Header File and Node class implementation
#ifndef NODEQUEUE_H
#define NODEQUEUE_H

//Libraries and Header Files
#include <iostream>
#include <header/DataType.h>
using namespace std;

//Class Node implementation
class Node{

  friend class NodeQueue;  //allows direct accessing of link and data from class NodeQueue

  public:
	//Default Constructor
        Node() :
	  m_next( NULL )
	{
	}
	//Parameterized Constructor
	Node(const DataType & data, Node * next = NULL) :
	  m_next( next ),
	  m_data( data )
	{
	}
	//Copy Constructor
	Node(const Node & other) :
	  m_next( other.m_next ),
	  m_data( other.m_data )
	{
	}
	//Returns data of object
        DataType & data(){ 
	  return m_data;
        }
        const DataType & data() const{  //gets const reference, can be used to access value of underlying data
          return m_data;
        }

  private:
    Node * m_next; 						
    DataType m_data;
};

//NodeQueue Class Declaration
class NodeQueue
{
	//Operator Overload for <<
	friend std::ostream &operator<<(std::ostream &os, const NodeQueue &nodeQueue);
	//Public Members and Methods
	public:
		//Constructors
		NodeQueue();
		NodeQueue(size_t size, const DataType &value);
		NodeQueue(const NodeQueue &other);
		~NodeQueue();

		//Assignment operator overload =
		NodeQueue &operator=(const NodeQueue &rhs);

		//Front and Back Functions
		DataType &front();
		const DataType &front() const;

		DataType &back();
		const DataType &back() const;

		//Push and Pop Functions to add/delete elements in Node queue
		void push(const DataType &value);
		void pop();

		//Size, empty, and full functions
		size_t size() const;
		bool empty() const;
		bool full() const;
		//Clear function to dynamically deallocate and delete queue
		void clear();
		//Serialize function to output queue to terminal
		void serialize(std::ostream &os) const;
	//Private Methods and Members
	private:
		Node *m_front;
		Node *m_back;
};


#endif /* NODEQUEUE_H */
