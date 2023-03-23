//Nicholas Ang
//Binary Search Tree CPP file

//Libraries and Header Files
#include "BinarySearchTree.h"
#include "BinaryNodeTree.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.cpp"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"
#include <iostream>

using namespace std;

//Place Node Function - determines where to add node in the tree
template<class ItemType>
auto BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,std::shared_ptr<BinaryNode<ItemType>> newNode)
{
	//Checks if subTreePtr is empty so that it can be placed into that spot
	if(subTreePtr == nullptr)
	{
		return newNode;
	}
	//Checks if the newNode value is smaller than current node value to decide where to place
	else if(subTreePtr->getItem() > newNode->getItem())
	{
		//Places to left side because newNode value is smaller
		auto tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNode);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	//Otherwise, newNode value is larger so it is put into right side of tree
	else
	{
		auto tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNode);
		subTreePtr->setRightChildPtr(tempPtr);
	}
	return subTreePtr;
}

//RemoveValue function - calls removeNode to remove values and searches through the tree, returns shared pointer of target
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool &isSuccessful) 
{
	//if subTreePtr is not valid, return false
	if(subTreePtr == nullptr)
	{
		isSuccessful = false;
	}
	//If valid, check if item is equal to target
	else if(subTreePtr->getItem() == target)
	{
		//Remove node if successful
		subTreePtr = removeNode(subTreePtr);
		isSuccessful = true;
	}
	//If item is larger than target, checks left side of lower values
	else if(subTreePtr->getItem() > target)
	{
		//Recursively calls removeValue to search through left side of tree
		auto tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	//otherwise, item is smaller than target so check right side of larger values
	else
	{
		//Recursively calls removeValue to search and remove target from right side of tree
		auto tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
		subTreePtr->setRightChildPtr(tempPtr);
	}
	return subTreePtr;
}

//RemoveNode method - removes node from tree based on 3 cases. no children, 1 child, 2 children 
template<class ItemType>
auto BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr)
{
	//Checks if there are no children, returns Node to be removed
	if((nodePtr->getLeftChildPtr() == nullptr) && (nodePtr->getRightChildPtr() == nullptr))
	{
		return nodePtr;
	}
	//Checks if left child only is available, returns left child
	else if((nodePtr->getLeftChildPtr() != nullptr) && (nodePtr->getRightChildPtr() == nullptr))
	{
		auto nodeToConnectPtr = nodePtr->getLeftChildPtr();
		return nodeToConnectPtr;
	}
	//checks if right child only is available, returns right child
	else if((nodePtr->getLeftChildPtr() == nullptr) && (nodePtr->getRightChildPtr() != nullptr))
	{
		auto nodeToConnectPtr = nodePtr->getRightChildPtr();
		return nodeToConnectPtr;
	}
	//checks if there are two children pointers, returns inorder successor 
	else
	{
		ItemType newNodeValue;
		auto tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
		nodePtr->setRightChildPtr(tempPtr);
		nodePtr->setItem(newNodeValue);
		return nodePtr;
	}
}

//RemoveLeftMostNode function - removes the leftmost leaf from tree
template<class ItemType>
auto BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, ItemType &inorderSuccessor)
{
	//Checks if there is a left child
	if(subTreePtr->getLeftChildPtr() == nullptr)
	{
		//sets inorderSuccessor to item in subTreePtr and removes subTreePtr using removeNode
		inorderSuccessor = subTreePtr->getItem();
		return removeNode(subTreePtr);
	}
	else
	{
		//Recursively calls removeLeftmostNode to find the left most leaf
		auto tempPtr = removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor);
		subTreePtr->setLeftChildPtr(tempPtr);
		return subTreePtr;
	}
}

//FindNode function - finds the pointer that the target value is in
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType &target) const
{
	//Checks if node tree is valid
	if(treePtr == nullptr)
	{
		return nullptr;
	}
	//Checks if the treeptr is the target and returns it
	else if(treePtr->getItem() == target)
	{
		return treePtr;
	}
	//If the value in the tree is larger than the target, check left side for target (left side has lower values) by recursively calling findNode
	else if(treePtr->getItem() > target)
	{
		return findNode(treePtr->getLeftChildPtr(), target);
	}
	//Otherwise, check the right side and recursively call findNode
	else
	{
		return findNode(treePtr->getRightChildPtr(), target);
	}
}

//Default Constructor - rootptr is nullptr
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
	rootPtr = nullptr;
}

//Parameterized constructor - sets rootptr to node with value rootItem and nullptr children
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType &rootItem)
{
	rootPtr = BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}

//Copy Constructor - calls copyTree inherited function 
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType> &tree)
{
	rootPtr = this->copyTree(tree.rootPtr);
}

//Destructor - calls inherited destroyTree method
template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
	this->destroyTree(rootPtr);
}

//IsEmpty method - checks if there is valid pointer as rootptr
template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
	//If rootptr is valid, return false as tree is not empty
	if(rootPtr != nullptr)
	{
		return false;
	}
	//otherwise, tree is empty so return true
	else
	{
		return true;
	}
}

//GetHeight method - calls inherited getHeightHelper method and returns height
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
	int height = this->getHeightHelper(rootPtr);
	return height;
}

//GetNumberOfNodes Method - calls inherited getNumberOfNodesHelper function and returns numNodes
template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes () const
{
	int numNodes = this->getNumberOfNodesHelper(rootPtr);
	return numNodes;
}

//GetRootData method - checks if there is a root pointer with a value
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw(PrecondViolatedExcept)
{
	//If rootptr is valid, get item from rootptr and return it
	if(rootPtr != nullptr)
	{
		ItemType item = this->rootPtr->getItem();
		return item;
	}
	//Otherwise throw error message
	else
	{
		throw PrecondViolatedExcept("Tree is empty");
	}
}

//SetRootData method
template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType &newData)
{
	//checks if there is a root already, if so replace with new data
	if(rootPtr != nullptr)
	{
		rootPtr->setItem(newData);
	}
	//Otherwise, create new Node with newData and set it to rootPtr
	else
	{
		rootPtr = std::make_shared<BinaryNode<ItemType>>(newData, nullptr, nullptr);
	}
}

//Add method - calls placeNode function to correctly place the value on the correct side and pointer
template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType &newEntry)
{
	//creates a node with newEntry value and calls placeNode
	auto node = std::make_shared<BinaryNode<ItemType>>(newEntry);
	rootPtr = placeNode(rootPtr, node);
	//Should Always return true as adding is dynamic
	return true;
}

//Remove function - calls removeValue function and if value is removed, return true. otherwise return false
template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType &target)
{
	bool isSuccessful = false;
	if(removeValue(rootPtr, target, isSuccessful))
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

//Clear method - calls inherited destroyTree function and resets smart pointer
template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{
	this->destroyTree(rootPtr);
	rootPtr.reset();
}

//GetEntry method - calls findNode and checks if it is nullptr or correct pointer
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType &anEntry) const throw(NotFoundException)
{
	auto node = findNode(rootPtr, anEntry);
	//If node is found, item is set to value inside the node and returned
	if(node != nullptr)
	{
		ItemType item = node->getItem();
		return item;
	}
	//Otherwise throw error that entry does not exist in the tree
	else
	{
		throw NotFoundException("Entry does not exist in tree");
	}
}

//Contains method - sets node to node found with given entry and returns true or false based on if found
template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType &anEntry) const
{
	auto node = findNode(rootPtr, anEntry);
	//If found node is not nullptr, returns true
	if(node != nullptr)
	{
		return true;
	}
	//Otherwise, value does not exist in the tree
	else
	{
		return false;
	}
}

//Preorder Traversal method - calls BinaryNodeTree preorder inherited method
template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType &)) const
{
this->preorder(visit,rootPtr);
}

//Inorder Traversal method - calls BinaryNodeTree inorder inherited method
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType &)) const
{
this->inorder(visit,rootPtr);
}

//Postorder Traversal method - calls BinaryNodeTree postorder inherited method
template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType &)) const
{
	this->postorder(visit,rootPtr);
}

//Operator Overload for =
//Same as BinaryNodeTree implementation of operator=
template<class ItemType>
BinarySearchTree<ItemType> &BinarySearchTree<ItemType>::operator=(const BinarySearchTree &rhs)
{
	//clears tree first
	clear();
	//checks self assignment
	if(this != &rhs)
	{
		//calls copyTree method to copy to desired tree and return the tree
		this = copyTree(&rhs);
		return *this;
	}
}
