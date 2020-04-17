#include "BiSexual.h"
#include <iostream>

using namespace std;



BiSexual::BiSexual()
{
	root = nullptr;
}

BiSexual::~BiSexual()
{
	MakeEmptyPublic();
}

BiSexual::BiSexual(BiSexual& oTree)
{
}

void BiSexual::operator=(BiSexual& oTree)
{
}

void BiSexual::MakeEmptyPublic() {
	MakeEmpty(root);
}

void BiSexual::MakeEmpty(TreeNode* node)
{
	if (!IsEmpty()) {
		if (node->left != nullptr)
			MakeEmpty(node->left);
		if (node->right != nullptr)
			MakeEmpty(node->right);
		delete node;

	}
	else
		root = nullptr;
}

bool BiSexual::IsEmpty()
{
	if (root == nullptr)
		return true;

	return false;
}

bool BiSexual::IsFull()
{
	try
	{
		TreeNode* temp = new TreeNode;

		delete temp;
		return false;
	}
	catch (bad_alloc e)
	{
		return true;
	}
}

int BiSexual::GetLength()
{
	return 0;
}

ItemType BiSexual::GetItem(int item, bool& found)
{
	return ItemType();
}

//void BiSexual::DeleteItem(int item)
//{
//	Delete(root, item);
//}

void BiSexual::ResetTree()
{
}

ItemType BiSexual::GetNextItem(bool& finished)
{
	return ItemType();
}

void BiSexual::Print(ofstream outfile)
{
}

void BiSexual::printTree()
{
	if (!IsEmpty()) {
		cout << "\n Tree 'order': \n";
		printTreePrivate(root, 0);
	}
	else
	{
		cout << "\n Tree is empty! \n";
	}
}

void BiSexual::BPutItem(ItemType item)
{
	BInsert(root, item);
}

int BiSexual::FindSmallestPublic()
{
	return FindSmallest(root);
}

TreeNode* BiSexual::returnNum(int num, TreeNode* node)
{
	if (node->info == num) {
		return node;
	}
	else if (num < node->info)
		returnNum(num, node->left);
	else if (num > node->info) {
		returnNum(num, node->right);
	}
}

void BiSexual::printTreePrivate(TreeNode* node, int space)
{
	if (node != nullptr) {
		space += 5;
		printTreePrivate(node->right, space);
		cout << "\n";
		for (int i = 5; i < space; i++)
			cout << " ";
		cout << node->info << endl;
		printTreePrivate(node->left, space);
	}




	/*if (node->left == nullptr && node->right == nullptr)
	{
		cout << node->info;
	}*/
}

void BiSexual::printAscending()
{
	if (!IsEmpty()) {
		cout << "\n Increasing order: \n";
		printAscendingPrivate(root);
	}
	else
		cout << "The Tree is empty dummy!";
}

void BiSexual::printDescending()
{
	if (!IsEmpty()) {
		cout << "\n Decreasing order: \n";
		printDescendingPrivate(root);
	}
	else
		cout << "The Tree is empty dummy!";
}

void BiSexual::printAscendingPrivate(TreeNode* node)
{
	if (node != nullptr) {
		if (node->left != nullptr)
			printAscendingPrivate(node->left);
		cout << node->info << ", ";
		if (node->right != nullptr)
			printAscendingPrivate(node->right);
	}
}

void BiSexual::printDescendingPrivate(TreeNode* node)
{
	if (node != nullptr) {
		if (node->right != nullptr)
			printDescendingPrivate(node->right);
		cout << node->info << ", ";
		if (node->left != nullptr)
			printDescendingPrivate(node->left);
	}
}

LeftOrRight BiSexual::Evaluation(ItemType item, ItemType compare)
{
	if (compare < item)
		return Less;
	else if (compare > item)
		return Greater;

	return Equal;
}

void BiSexual::BInsert(TreeNode* &node, ItemType item)
{
	if (node == nullptr)
	{
		node = new TreeNode;
		node->left = nullptr;
		node->right = nullptr;
		node->info = item;
	}
	else if (item < node->info)
		BInsert(node->left, item);
	else
		BInsert(node->right, item);
}
void BiSexual::DeleteNum(int num) {
	if (!IsEmpty())
		DeleteNode(root, num);
	else
		cout << "Tree is empty. Error deleting emptiness :/ \n";
}

void BiSexual::DeleteNode(TreeNode* node, int num) {
	if (root->info == num)
		DeleteRoot();
	else
	{
		if (num < node->info && node->left != nullptr) {
			if (node->left->info == num)
				DeleteMatch(node, node->left, true);
			else
			DeleteNode(node->left, num);

		}
		else if (num > node->info&& node->right != nullptr) {
			if (node->right->info == num)
				DeleteMatch(node, node->right, false);
			else
			DeleteNode(node->right, num);

		}
		if (node->left == nullptr && node->right == nullptr && num != node->info)
		cout << "\nNumber " << num <<" was not deleted because it was not found!";
	}
	
}

void BiSexual::DeleteRoot() {
	int smallestInRightSubtree;
	TreeNode* deletenode = root;
	if (deletenode->right != nullptr) {
		smallestInRightSubtree = FindSmallest(deletenode->right);
	}
	else
		smallestInRightSubtree = deletenode->left->info;

	DeleteNode(deletenode, smallestInRightSubtree);
	deletenode->info = smallestInRightSubtree;
}

void BiSexual::DeleteMatch(TreeNode* parent, TreeNode* match, bool left) {
	TreeNode* deleteptr;
	int num = match->info;
	int smallestInRightSubtree;
	if (match->left == nullptr && match->right == nullptr) {
		deleteptr = match;
		if (left == true)
			parent->left = nullptr;
		else
			parent->right = nullptr;
		delete deleteptr;
		cout << "The number has been deleted.";
	}
	else if (match->left == nullptr && match->right != nullptr) {
		if (left == true)
			parent->left = match->right;
		else
			parent->right = match->right;
		match->right = nullptr;
		deleteptr = match;
		delete deleteptr;
		cout << "The number has been deleted.";

	}
	else if (match->left != nullptr && match->right == nullptr) {
		if (left == true)
			parent->left = match->left;
		else
			parent->right = match->left;
		match->left = nullptr;
		deleteptr = match;
		delete deleteptr;
		cout << "The number has been deleted.";
	}
	else
	{
		if (match->right != nullptr)
			smallestInRightSubtree = FindSmallest(match->right);
		else
			smallestInRightSubtree = match->info;
		DeleteNode(match, smallestInRightSubtree);
		match->info = smallestInRightSubtree;
	}
}

int BiSexual::FindSmallest(TreeNode* node) {
	if (!IsEmpty()) {
		if (node->left != nullptr) {
			return FindSmallest(node->left);
		}
		else
			return node->info;
	}

}