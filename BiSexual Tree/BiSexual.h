#ifndef BiSexual_h
#define BiSexual_h

#include <iostream>
#include <fstream>

using namespace std;

typedef int ItemType;

struct TreeNode
{
	ItemType info;
	TreeNode* left;
	TreeNode* right;
};

enum LeftOrRight
{
	Greater, Less, Equal
};


class BiSexual
{
public:
	BiSexual();
	~BiSexual();

	void MakeEmptyPublic();
	bool IsEmpty();
	bool IsFull();
	void printTree();
	void printAscending();
	void printDescending();
	void DeleteNum(int num);
	void BPutItem(ItemType item);
	int FindSmallestPublic();
	TreeNode* returnNum(int num, TreeNode* node);

private:
	TreeNode* root;

	void MakeEmpty(TreeNode* node);
	void printTreePrivate(TreeNode* node, int space);
	void printAscendingPrivate(TreeNode* node);
	void printDescendingPrivate(TreeNode* node);

	void BInsert(TreeNode*& node, ItemType item);
	void DeleteRoot();
	void DeleteNode(TreeNode* node, int num);
	void DeleteMatch(TreeNode* parent, TreeNode* match, bool left);
	int FindSmallest(TreeNode* node);
};

#endif // !BiSexual
