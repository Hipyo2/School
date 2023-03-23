//Nicholas Ang
//Binary Tree Interface Header File

#ifndef BINARY_TREE_INTERFACE
#define BINARY_TREE_INTERFACE

//Binary Tree Interface Class Declaration
template<class ItemType>
class BinaryTreeInterface
{
	//Public Methods
	public:
		//Pure Virtual Interface Methods
		virtual bool isEmpty() const = 0;
		virtual int getHeight() const = 0;
		virtual int getNumberOfNodes() const = 0;
		virtual ItemType getRootData() const = 0;
		virtual void setRootData(const ItemType &newData) = 0;
		virtual bool add(const ItemType &newData) = 0;
		virtual bool remove(const ItemType &target) = 0;
		virtual void clear() = 0;
		virtual ItemType getEntry(const ItemType &target) const = 0;
		virtual bool contains(const ItemType &target) const = 0;
		virtual void preorderTraverse(void visit(ItemType &)) const = 0;
		virtual void inorderTraverse(void visit(ItemType &)) const = 0;
		virtual void postorderTraverse(void visit(ItemType &)) const = 0;
		virtual ~BinaryTreeInterface () {}
};

#endif /*BINARY_TREE_INTERFACE*/
