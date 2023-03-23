//Nicholas Ang
//Binary Node CPP file

//Header Files
#include "BinaryNode.h"

//Default constructor - sets all values to null values
template<class ItemType>
BinaryNode<ItemType>::BinaryNode()
{
	item = NULL;
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;
}

//Parameterized constructor - creates a node with no children
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType &anItem)
{
	item = anItem;
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;
}

//Parameterized constructor - creates a node with children pointers
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType &anItem, std::shared_ptr<BinaryNode<ItemType>> leftPtr, std::shared_ptr<BinaryNode<ItemType>> rightPtr)
{
	item = anItem;
	leftChildPtr = leftPtr;
	rightChildPtr = rightPtr;
}

//Setter - sets item to given item value
template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType &anItem)
{
	item = anItem;
}

//Getter - gets item value held by the node
template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
	return item;
}

//isLeaf function checks a node to see if it has any children pointers - returns true if it has no left or right child pointers
template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
	if(leftChildPtr == nullptr && rightChildPtr == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Getter - gets left child pointer, auto type to return either shared or normal pointers
template<class ItemType>
auto BinaryNode<ItemType>::getLeftChildPtr() const
{
	return leftChildPtr;
}

//Getter - gets right child pointer, auto type to return either shared or normal pointers
template<class ItemType>
auto BinaryNode<ItemType>::getRightChildPtr() const
{
	return rightChildPtr;
}

//Setter - sets left child ptr with given pointer
template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr)
{
	leftChildPtr = leftPtr;
}

//Setter - sets right child ptr with given pointer
template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr)
{
	rightChildPtr = rightPtr;
}
