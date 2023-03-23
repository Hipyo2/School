//Nicholas Ang
//Binary Search Tree Header File

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

//Libraries and Header Files
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"
#include <memory>

//Binary Search Tree Class Declaration
template<class ItemType>
class BinarySearchTree: public BinaryNodeTree<ItemType>
{
	//Private Members
	private:
	std::shared_ptr <BinaryNode<ItemType>> rootPtr;
	//Protected Methods
	protected:
		auto placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,std::shared_ptr<BinaryNode<ItemType>> newNode);
		std::shared_ptr<BinaryNode<ItemType>> removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool &isSuccessful) override;
		auto removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr);
		auto removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, ItemType &inorderSuccessor);
		std::shared_ptr<BinaryNode<ItemType>> findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType &target) const;
	//Public Methods
	public:
		//Constructors and Destructors
		BinarySearchTree();
		BinarySearchTree(const ItemType &rootItem);
		BinarySearchTree(const BinarySearchTree<ItemType> &tree);
		virtual ~BinarySearchTree();

		bool isEmpty() const;
		int getHeight() const;
		int getNumberOfNodes () const;
		ItemType getRootData() const throw(PrecondViolatedExcept);
		void setRootData(const ItemType &newData);
		bool add(const ItemType &newEntry);
		bool remove(const ItemType &target);
		void clear();
		ItemType getEntry(const ItemType &anEntry) const throw(NotFoundException);
		bool contains(const ItemType &anEntry) const;
		void preorderTraverse(void visit(ItemType &)) const;
		void inorderTraverse(void visit(ItemType &)) const;
		void postorderTraverse(void visit(ItemType &)) const;
		BinarySearchTree<ItemType> &operator=(const BinarySearchTree &rhs);
};

//#include "BinarySearchTree.cpp"
#endif /*BINARY_SEARCH_TREE*/
