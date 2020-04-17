#include "BiSexual.h"
#include <iostream>
using namespace std;

BiSexual::BiSexual() {
	root = nullptr;
}
BiSexual::~BiSexual() {

}

bool BiSexual::insertItem(int item)
{
	bool spotFound = false;
	node* position = root;
	node* previous = root;
	if (root == nullptr) {
		node* newnode = new node;
		root = newnode;
		root->info = item;
		root->left = nullptr;
		root->left = nullptr;
	}
	else {
		while (!spotFound)
		{
			if (item > position->info) {
				position = position->right;
			}
			else
			{
				position = position->left;
			}
			if (position == nullptr) {
				node* newnode = new node;
				newnode = position;
				newnode->info = item;
			}
		}
	}
	return 0;
}

sign BiSexual::eval(int one, int compare)
{
	if (one < compare)
		return LESS;
	if (one > compare)
		return GREATER;
	if (one == compare)
		return EQUAL;
	cout << "\n Not < or > \n";
	return LESS;
}