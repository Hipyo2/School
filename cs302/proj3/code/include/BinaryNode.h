//Nicholas Ang
//Binary Node Header File

#ifndef BINARY_NODE
#define BINARY_NODE

//Libraries and Header Files
#include <memory>

//Binary Node Declaration
template <class ItemType>
class BinaryNode
{
	//Private Members
	private:
		ItemType item;
		std::shared_ptr<BinaryNode<ItemType>> leftChildPtr;
		std::shared_ptr<BinaryNode<ItemType>> rightChildPtr;

	//Public Methods
	public:
		//Constructors and Destructors
		BinaryNode();
		BinaryNode(const ItemType &anItem);
		BinaryNode(const ItemType &anItem, std::shared_ptr<BinaryNode<ItemType>> leftPtr, std::shared_ptr<BinaryNode<ItemType>> rightPtr);

		//Getters, setters, other functions
		void setItem(const ItemType &anItem);
		ItemType getItem() const;
		bool isLeaf() const;
		auto getLeftChildPtr() const;
		auto getRightChildPtr() const;
		void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr);
		void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr);
};

//#include "BinaryNode.cpp"
#endif /*BINARY_NODE*/
