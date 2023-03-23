//Nicholas Ang
//Binary Node Tree Header File

#ifndef BINARY_NODE_TREE
#define BINARY_NODE_TREE

//Libraries and Header files
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"

//Binary Node Tree Class Declaration
template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
	//Private Members
	private:
		std::shared_ptr<BinaryNode<ItemType>> rootPtr;

	//Protected Methods
	protected:
		int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
		int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
		auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr);
		virtual std::shared_ptr<BinaryNode<ItemType>> removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool &isSuccessful);
		std::shared_ptr<BinaryNode<ItemType>> moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);
		virtual std::shared_ptr<BinaryNode<ItemType>> findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,const ItemType &target, bool &isSuccessful) const;
		auto copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;
		void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);
		void preorder(void visit(ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
		void inorder(void visit(ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
		void postorder(void visit(ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;

	//Public Methods
	public:
		//Constructors and Destructors
		BinaryNodeTree();
		BinaryNodeTree(const ItemType &rootItem);
		BinaryNodeTree(const ItemType &rootItem, const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr, const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);
		BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>> &tree);
		virtual ~BinaryNodeTree();

		bool isEmpty() const;
		int getHeight() const;
		int getNumberOfNodes () const;
		ItemType getRootData() const throw(PrecondViolatedExcept);
		bool add(const ItemType &newData);
		bool remove(const ItemType &data);
		void clear();
		ItemType getEntry(const ItemType &anEntry) const throw(NotFoundException);
		bool contains(const ItemType &anEntry) const;
		void preorderTraverse(void visit(ItemType &)) const;
		void inorderTraverse(void visit(ItemType &)) const;
		void postorderTraverse(void visit(ItemType &)) const;

		//Operator Overload
		BinaryNodeTree &operator=(const BinaryNodeTree &rhs);
};
//#include "BinaryNodeTree.cpp"
#endif /*BINARY_NODE_TREE*/
