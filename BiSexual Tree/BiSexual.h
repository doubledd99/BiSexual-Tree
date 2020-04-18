#ifndef BiSexual_h
#define BiSexual_h

#include <iostream>//libraries used to run program
#include <fstream>

using namespace std;

typedef int ItemType;//leftover from early in the lab where we would have had to to tree with strings

struct TreeNode//struct definition of each node in the tree
{
	ItemType info;//integer called info holds the number in the tree
	TreeNode* left;//pointer to the next smallest node in this subtree
	TreeNode* right;//pointer to the next biggest node in this subtree
};


class BiSexual //class creation
{
public:
	BiSexual();//default constructor prototype
	~BiSexual();//default destructor prototype

			//these are method prototypes
	void MakeEmptyPublic(); //wrapper for makeempty method
	bool IsEmpty();//returns true if the tree is empty
	bool IsFull();//returns true if cannot allocate more memory
	void printTree();//prints information in tree format wrapper
	void printAscending();//prints information in ascending order wrapper
	void printDescending();//prints info in descending order wrapper
	void DeleteNum(int num);//wrapper to deleteNode
	void BPutItem(ItemType item); //wrapper for Binsert
	int FindSmallestPublic();//wrapper for FindSmallest
	TreeNode* returnNum(int num, TreeNode* node); //returns pointer for given number and starting position subject to change with recursion

private:
	TreeNode* root;//pointer of root

	void MakeEmpty(TreeNode* node);//deletes each node
	void printTreePrivate(TreeNode* node, int space);//prints in tree format
	void printAscendingPrivate(TreeNode* node);//prints in ascending order format
	void printDescendingPrivate(TreeNode* node);//prints in descending order format

	void BInsert(TreeNode*& node, ItemType item);//inserts new item into tree in the correct place
	void DeleteRoot();//deletes root number and replaces with appropriate value given appropriate circumstances
	void DeleteNode(TreeNode* node, int num);//finds where the number is that is to be deleted
	void DeleteMatch(TreeNode* parent, TreeNode* match, bool left);//actually deletes value desired
	int FindSmallest(TreeNode* node);//returns int of smallest value in the subtree
};

#endif // !BiSexual
