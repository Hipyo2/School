//Nicholas Ang
//Binary Node Tree CPP file

#include "BinaryNodeTree.h"
#include "BinaryNode.h"
#include "BinaryNode.cpp"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"
#include <iostream>
using namespace std;

//GetHeightHelper - recursively goes through each node and adds 1 everytime it goes down
//Given function from slides
template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
	//If next ptr is null, return 0
	if(subTreePtr == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
	}
}

//GetNumberOfNodesHelper - recursively goes through each node and adds 1 every visit to a node, similar to heighthelper
template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
	//If pointer is null, return 0
	if(subTreePtr == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
	}
}

//BalancedAdd - returns shared pointer or normal pointer
template<class ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
	//If is a leaf or empty node, add new node to tree
	if(subTreePtr == nullptr)
	{
		return newNodePtr;
	}
	else
	{
		auto leftPtr = subTreePtr->getLeftChildPtr();
		auto rightPtr = subTreePtr->getRightChildPtr();
		//If left side is higher than right, add to right
		if(getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			rightPtr = balancedAdd(rightPtr, newNodePtr);
			subTreePtr->setRightChildPtr(rightPtr);
		}
		else
		{
			//otherwise add to left side
			leftPtr = balancedAdd(leftPtr, newNodePtr);
			subTreePtr->setLeftChildPtr(leftPtr);
		}
			return subTreePtr;
	}
}

//Remove Value function - returns shared ptr that gets deleted after
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool &isSuccessful)
{
	//Checks if the tree is valid and holds values
	if(subTreePtr != nullptr)
	{
		//First checks if current node has the target
		if(subTreePtr->getItem() == target)
		{
			isSuccessful = true;
			//Calls moveValuesUpTree function to shift the target, and removes the value by returning the pointer
			subTreePtr = moveValuesUpTree(subTreePtr);
			return subTreePtr;
		}
		else
		{
			//Checks left side if not found
			auto node = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
			subTreePtr->setLeftChildPtr(node);
			//If found, value is removed 
			if(isSuccessful == true)
			{
			}
			else
			{
				//Check right side after left side
				node = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
				subTreePtr->setRightChildPtr(node);
			}
			//returns removed value
			return subTreePtr;
		}
	}
	else
	{
		//Otherwise remove nothing
		return nullptr;
	}
}

//Move Values up Tree function - moves target pointer down
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
	auto leftPtr = subTreePtr->getLeftChildPtr();
	auto rightPtr = subTreePtr->getRightChildPtr();
	//Checks tree for validity
	if(subTreePtr == nullptr)
	{
		return nullptr;
	}
	else
	{
		//Checks if there is a left value first
		if(getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			//Moves Left side up
			subTreePtr->setItem(leftPtr->getItem());
			leftPtr = moveValuesUpTree(leftPtr);
			subTreePtr->setLeftChildPtr(leftPtr);
			return subTreePtr;
		}
		else
		{
			//Checks if right side is null
			if(rightPtr == nullptr)
			{
				return nullptr;
			}
			//If there is a right side value, moves it up
			else
			{
				subTreePtr->setItem(rightPtr->getItem());
				rightPtr = moveValuesUpTree(rightPtr);
				subTreePtr->setLeftChildPtr(rightPtr);
				return subTreePtr;
			}
		}
	}
}

//Find Node Function - returns shared pointer of the node target
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,const ItemType &target, bool &isSuccessful) const
{
	//Checks if tree is valid first
	if(treePtr == nullptr)
	{
		return treePtr;
	}
	else
	{
		//Checks if current ptr is the target, returns pointer if true
		if(treePtr->getItem() == target)
		{
			isSuccessful = true;
			return treePtr;
		}
		else
		{
			//if still not found, recursively check left side of tree
			if(isSuccessful == false)
			{
				auto targetNode = findNode(treePtr->getLeftChildPtr(), target, isSuccessful);
				//if still not found on left side, recursively check right side of tree until found
				if(isSuccessful == false)
				{
					targetNode = findNode(treePtr->getRightChildPtr(), target, isSuccessful);
				}
				return targetNode;
			}
		}
	}
}

//Copy Tree Function - auto type returns shared pointer or normal pointer
template<class ItemType>
auto BinaryNodeTree<ItemType>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
{
	//Creates new pointer
	std::shared_ptr<BinaryNode<ItemType>> newTreePtr;
	if(oldTreeRootPtr != nullptr)
	{
		//Copies over shared pointer of old tree and sets left and right pointers, recursively copies through tree
		newTreePtr=std::make_shared<BinaryNodeTree<ItemType>>(oldTreeRootPtr->getItem(), nullptr, nullptr);
		newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
	}
	return newTreePtr;
}

//Destroy Tree function - resets shared pointers of tree
template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
	//Checks if tree node is valid pointer
	if(subTreePtr != nullptr)
	{
		//Resets shared pointers of left and right before reseting the parent pointer
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		subTreePtr.reset();
	}
}

//Preorder Protected method
template<class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	//Checks if treeptr is valid pointer
	if(treePtr == nullptr)
	{
	}
	else
	{
		//Gets the value in current node and outputs it with visit, then recursively outputs left and right child pointers
		ItemType value = treePtr->getItem();
		visit(value);
		preorder(visit,treePtr->getLeftChildPtr());
		preorder(visit,treePtr->getRightChildPtr());
	}
}

//Inorder Protected method
template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	//Checks if treeptr is valid pointer
	if(treePtr == nullptr)
	{
	}
	else
	{
		//recursively visits with inorder from left, outputs value with visit, then visits right
		inorder(visit,treePtr->getLeftChildPtr());
		ItemType value = treePtr->getItem();
		visit(value);
		inorder(visit,treePtr->getRightChildPtr());
	}
}

//Postorder protected method
template<class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	//Checks if treeptr is valid pointer
	if(treePtr == nullptr)
	{
	}
	else
	{
		//Recursively visits left and right and then outputs value with visit
		postorder(visit,treePtr->getLeftChildPtr());
		postorder(visit,treePtr->getRightChildPtr());
		ItemType value = treePtr->getItem();
		visit(value);
	}
}



//Public Methods
//Default Constructor - rootptr is nullptr
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree()
{
	rootPtr = nullptr;
}

//Parameterized constructor - sets rootptr to node with value rootItem and nullptr children
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType &rootItem)
{
	rootPtr = BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}

//Parameterized constructor - sets rootptr to node with value rootItem and respective left and right children
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType &rootItem, const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr, const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
{
	rootPtr = BinaryNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));
}

//Copy Constructor - calls copyTree function
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>> &tree)
{
	rootPtr = copyTree(tree.rootPtr);
}

//Destructor - calls destroyTree method
template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
	destroyTree(rootPtr);
}

//isEmpty method - checks if rootptr is nullptr. there are no left and right childs if rootptr is nullptr
template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
	if(rootPtr == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Get Height method - sets height using getHeightHelper and is returned
template<class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
	int height = getHeightHelper(rootPtr);
	return height;
}

//GetNumberOfNodes method - sets numNodes using getNumberOfNodesHelper and is returned
template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes () const
{
	int numNodes = getNumberOfNodesHelper(rootPtr);
	return numNodes;
}

//GetRootData method - calls getItem on rootptr to get value from root node
template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const throw(PrecondViolatedExcept)
{
	//Checks if tree is valid and has proper root
	if(rootPtr != nullptr)
	{
		//returns value in root
		ItemType item = rootPtr->getItem();
		return item;
	}
	else
	{
		//Throws error message if tree is empty
		throw PrecondViolatedExcept("Tree is empty");
	}
}

//Add method - adds shared ptr or normal ptr node to tree
template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType &newData)
{
	//creates a new node using given data and calls balancedAdd to add to tree, keeping it balanced
	auto node = std::make_shared<BinaryNode<ItemType>>(newData);
	rootPtr = balancedAdd(rootPtr, node);
	//Should always be successful
	return true;
}

//Remove method - calls removeValue function to remove target data
template<class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType &data)
{
	bool isSuccessful = false;
	//If removeValue worked, returns true
	if(removeValue(rootPtr, data, isSuccessful))
	{
	return true;
	}
	//Otherwise, returns false
	else
	{
	//cout << "did not remove data";
	return false;
	}
}

//Clear Method - calls destroyTree before resetting root
template<class ItemType>
void BinaryNodeTree<ItemType>::clear()
{
	destroyTree(rootPtr);
	rootPtr.reset();
}

//GetEntry method - findsNode with target value and returns value from it
template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType &anEntry) const throw(NotFoundException)
{
	bool isSuccessful = false;
	//Shared pointer or normal pointer node from findNode
	auto node = findNode(rootPtr, anEntry, isSuccessful);

	//If found, getItem from node and return it
	if(isSuccessful == true)
	{
		ItemType item = node->getItem();
		return item;
	}
	//Otherwise throw error message
	else
	{
		throw NotFoundException("Entry does not exist in tree");
	}
}

//Contains method - checks if entry exists in tree
template<class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType &anEntry) const
{
	bool isSuccessful = false;
	findNode(rootPtr, anEntry, isSuccessful);
	//If node is found, return true
	if(isSuccessful == true)
	{
		return true;
	}
	//Returns false if entry does not exist in tree
	else
	{
		return false;
	}
}

//Preorder Traverse - calls preorder protected method to traverse tree
template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType &)) const
{
	preorder(visit,rootPtr);
}

//Inorder method - calls inorder protected method to traverse tree
template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType &)) const
{
	inorder(visit,rootPtr);
}

//Postorder method - calls postorder protected method to traverse tree
template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType &)) const
{
	postorder(visit,rootPtr);
}

//Operator Overload = 
template<class ItemType>
BinaryNodeTree<ItemType> &BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree<ItemType> &rhs)
{
	//Clears tree
	clear();
	//checks for self assignment
	if(this != &rhs)
	{
	//Calls copyTree method to copy tree and return it
	this = copyTree(&rhs);
	return *this;
	}
}
