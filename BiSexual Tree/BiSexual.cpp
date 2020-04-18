#include "BiSexual.h"
#include <iostream>		//libraries that are used for the program

using namespace std;	//standard library refrence



BiSexual::BiSexual()//default constructor
{
	root = nullptr;//sets root to nullptr
}

BiSexual::~BiSexual()//default destructor
{
	MakeEmptyPublic();//calls makeempty (private) with root parameter
}

void BiSexual::MakeEmptyPublic() {//public (wrapper) for makeempty method
	MakeEmpty(root);//calls makeempty with the starting node* as root. (deletes whole tree)
}

void BiSexual::MakeEmpty(TreeNode* node)//deletes each node. Used recursively with subsequent
										//calls each time a node (left or right) isn't nullptr
{
	if (!IsEmpty()) {//as long as root != nullptr
		if (node->left != nullptr)//if there is a left node recursive call
			MakeEmpty(node->left);
		if (node->right != nullptr)//if there is a right node recursive call
			MakeEmpty(node->right);

		//For each node in the tree there will be a recursive call, therefore each node, starting
		//with the node furthest removed from the root, will be deleted and set to nullptr
		cout << "deleting " << node->info << endl;//informs user what node is being deleted
		delete node;	//deletes node based on which call is in scope	
		node = nullptr;//sets each node to nullptr


	}
	else
		root = nullptr;//if this is not here the root will not be set to nullptr
					   //which messes up the destructor
}

bool BiSexual::IsEmpty()//returns true if the tree doesnt contain any nodes or root
{
	if (root == nullptr)//if the root is nullptr the tree is empty
		return true;

	return false;
}

bool BiSexual::IsFull()//test to determine if the system can allocate memory for new node*
{
	try //try catch statement to allocate memory
	{
		TreeNode* temp = new TreeNode;//tries to allocate memory for a new node

		delete temp; //deletes temporary test node
		return false;//if the above succeeds the system can allocate memory for atleast 1 more node*
	}
	catch (bad_alloc e)//bad allocation means system cannot acquire new memory for some reason
	{
		return true; //system cant alloc new memory and therefore (full)
	}
}

void BiSexual::printTree()//prints tree in visual tree format (this is just a wrapper)
{
	if (!IsEmpty()) {//as long as tree isnt empty there is no need to print blanks
		cout << "\n Tree 'order': \n"; //informs user of which list type is printing
		printTreePrivate(root, 0); //calls the private function which actually does something with
								   //parameters root(to start) and 0 for spaces(to start)
	}
	else//if the tree is empty it wont print anything
	{
		cout << "\n Tree is empty! \n"; //informs user of their misfortune
	}
}

void BiSexual::BPutItem(ItemType item)//starts process to insert a new item (just a wrapper)
{
	if(!IsFull())//will continue as long as new memory is available
		BInsert(root, item);//calls this method with params:
							//root(which tree to insert in and the integer value to insert
}

int BiSexual::FindSmallestPublic()//wrapper to find the smallest node in the tree
{
	return FindSmallest(root);//returns the smallest node in the tree via this method
}

TreeNode* BiSexual::returnNum(int num, TreeNode* node) //returns pointer of the node containing specified number via provided param starting point
{
	if (node->info == num) {//if the node IS containing the number returns ptr to this node
		return node;
	}
	else if (num < node->info)//if the number is smaller than the specified one to find recursive call with new starting point in the left child
		returnNum(num, node->left);
	else if (num > node->info) {//if the number is bigger than the specified one to find recursive call with new starting point in the right child
		returnNum(num, node->right);
	}
}

void BiSexual::printTreePrivate(TreeNode* node, int space) //function to be called recursively that prints tree in specified tree format
{
	if (node != nullptr) {//if the node exists proceed
		space += 5; //adds 5 spaces in each recursive call
		printTreePrivate(node->right, space);//recursive call with 5 more spaces each time finally reaching the farthest to the right node, which will be printed as the top in this sideways view
		cout << "\n";//after the furthest to the right node is found a newline will be created and subsequent moments after as well
		for (int i = 5; i < space; i++)//adds 5 spaces to the screen
			cout << " ";
		cout << node->info << endl;//prints the integer value contained in this node to the screen
		printTreePrivate(node->left, space); //recursive call with each node going to the left this time
//The above recursive call will start at the top again trying to go to the right first therefore printing all nodes integers to the screen in the desired fashion
	}
}

void BiSexual::printAscending()//prints the numbers in increasing order (just a wrapper)
{
	if (!IsEmpty()) {//as long as the tree exists
		cout << "\n Increasing order: \n";//informs user which order will be displayed
		printAscendingPrivate(root);//calls private method which actually does something
	}
	else
		cout << "The Tree is empty dummy!";//informs user of their misfortune
}

void BiSexual::printDescending()//wrapper for method that prints the biggest number first and subsequent smaller after that
{
	if (!IsEmpty()) {//as long as the tree exists
		cout << "\n Decreasing order: \n";//informs user which order will be displayed
		printDescendingPrivate(root);//private method which actually does the displaying
	}
	else
		cout << "The Tree is empty dummy!";
}

void BiSexual::printAscendingPrivate(TreeNode* node)//will be called recursively to print in ascending order
{
	if (node != nullptr) {//if the node exists
		if (node->left != nullptr)//if there is a next node that is smaller than itself proceed
			printAscendingPrivate(node->left);//recursive call with the next smallest value in its subtree
		cout << node->info << ", ";//prints the integer in scope along with spacing to please Busch's eyes
		if (node->right != nullptr)//if there is no smaller node it goes to the next biggest node
			printAscendingPrivate(node->right);//recursive call to start with the next biggest node in subtree
//Because the recursive calls start with proceeding to recursively call the next smallest number 
//the first number to be outputted will therefore be the smallest node(all the way left)
	}
}

void BiSexual::printDescendingPrivate(TreeNode* node) //will be called recursively to print in ascending order
{
	if (node != nullptr) {//if the node exists
		if (node->right != nullptr)//if there is a next node that is smaller than itself proceed
			printDescendingPrivate(node->right);//recursive call with the next biggest value in its subtree
		cout << node->info << ", ";//prints the integer in scope along with spacing to please Busch's eyes
		if (node->left != nullptr)//if there is no bigger node it goes to the next smallest node
			printDescendingPrivate(node->left);//recursive call to start with the next smallest node in subtree
//Because the recursive calls start with proceeding to recursively call the next biggest number 
//the first number to be outputted will therefore be the biggest node(all the way right)
	}
}

void BiSexual::BInsert(TreeNode* &node, ItemType item)//method to actually do the inserting and creating of a new node with parameters node(location) and integer to be inserted
{
	if (node == nullptr)//if the node doesnt exist it is a valid spot to place newnode
	{
		node = new TreeNode; //created new memory for newnode
		node->left = nullptr; //sets children pointers to nullptr
		node->right = nullptr;// see above
		node->info = item;//places integer into variable inside node
	}
	else if (item < node->info) //if the number to be inserted is smaller than current node recursive call to the next smallest node in subtree
		BInsert(node->left, item);
	else
		BInsert(node->right, item);//if the number to be inserted is bigger (or equal) to the current node recursive call with next biggest node in subtree
}
void BiSexual::DeleteNum(int num) {//delete wrapper for real delete method takes param number to be deleted
	if (!IsEmpty())//as long as the tree exists
		DeleteNode(root, num);//calls method to delete number with params: root starting point and number to be deleted
	else
		cout << "Tree is empty. Error deleting emptiness :/ \n";
}

void BiSexual::DeleteNode(TreeNode* node, int num) {//deletes node given number to delete taking another parameter(starting point which changes based on recirsion)
	if (root->info == num)//if the number to be deleted is the root node special method to deal with this
		DeleteRoot();//deletes root node replacing it with smallest in right subtree
	else//if the number to be deleted isnt the root then:
	{
		if (num < node->info && node->left != nullptr) {//if the number is smaller than current node and the left child exists then:
			if (node->left->info == num)//if the next smallest node contains the desired number
				DeleteMatch(node, node->left, true); //calls method to delete item with parameters (parent node of number to be deleted, node to be deleted, and if it is the left child of parent node boolean value)
			else
			DeleteNode(node->left, num); //if the next smallest node doenst contain desired value recursive call with starting point the next smallest node
		}
		else if (num > node->info&& node->right != nullptr) {//if the desired number is bigger than current node and the right child exists then:
			if (node->right->info == num) //if the right child contains the number
				DeleteMatch(node, node->right, false); //calls method to delete node taking parameters (current node "parent",node to be deleted, and boolean value true if the desired value is the left child of parent node
			else
			DeleteNode(node->right, num);//recursive call with starting point the right child

		}
		if (node->left == nullptr && node->right == nullptr && num != node->info)//if this node has no children and this node does not contain the desired node to be deleted displays "error" to user
		cout << "\nNumber " << num <<" was not deleted because it was not found!";
	}
	
}

void BiSexual::DeleteRoot() {//method to delete root node
	int smallestInRightSubtree; //creates integer to house the integer value of the smallest in right subtree 
	TreeNode* deletenode = root; //created new node* deletenode with address of the root
	if (deletenode->right != nullptr) { //if there is a right child then:
		smallestInRightSubtree = FindSmallest(deletenode->right);//method call to find the smallest value in the right subtree
	}
	else //if there isnt a right subtree then:
		smallestInRightSubtree = deletenode->left->info; //sets smallest value equal to the left child

	DeleteNode(deletenode, smallestInRightSubtree);//deletes node of the smallest in right subtree
	deletenode->info = smallestInRightSubtree;//replaces root integer with smallest in right subtree number
}

void BiSexual::DeleteMatch(TreeNode* parent, TreeNode* match, bool left) {//method to actually do the deleting of a node given parent*, node* that contains desired deleted value, and a bool set to true if the desired delete node is the left child of parent node
	TreeNode* deleteptr;//creates pointer to be set to node that is to be erased
	int num = match->info; //sets this variable equal to the current node int value
	int smallestInRightSubtree;//creates int to house smallest in right subtree value
	if (match->left == nullptr && match->right == nullptr) {//if the node to be deleted has no children:
		deleteptr = match;//sets deleteptr equal to current node
		if (left == true)//if this is the left child of parent node:
			parent->left = nullptr;//sets parent left pointer to nullptr
		else
			parent->right = nullptr;//sets parent right pointer to nullptr
		delete deleteptr;
		cout << "The number has been deleted.";//informs user number has been deleted
	}
	else if (match->left == nullptr && match->right != nullptr) {//if the node to be deleted has a right child but no left clild:
		if (left == true)//if this is the left child of parent:
			parent->left = match->right;//sets parents left child equal to the deleted node's right child
		else
			parent->right = match->right; //if this is the right child of parent:
		match->right = nullptr;//sets deleted node's right child to nullptr
		deleteptr = match; //sets deleteptr equal to the soon to be deleted node
		delete deleteptr; //deletes desired node
		cout << "The number has been deleted.";//informs user

	}
	else if (match->left != nullptr && match->right == nullptr) {//if the desired deleted node has a left child but no right child then:
		if (left == true)//if this node is the left child of parent node:
			parent->left = match->left;//sets parents left pointer to deleted nodes left pointer
		else
			parent->right = match->left;//if this node is the right child of parent node:
		match->left = nullptr;//sets deleted node's left child to nullptr
		deleteptr = match; //sets deleteptr equal to the soon to be deleted node
		delete deleteptr; //deletes desired node
		cout << "The number has been deleted.";//informs user
	}
	else //specific case where node to be deleted has not met above requirements and needs to be replaced instead of outright deleted
	{
		if (match->right != nullptr)//if there is a right subtree:
			smallestInRightSubtree = FindSmallest(match->right);//finds smallest in right subtree
		else
			smallestInRightSubtree = match->info;//if the node doesnt have a right subtree:
		DeleteNode(match, smallestInRightSubtree); //method call to delete smallest in right subtree with starting position the current node to save time
		match->info = smallestInRightSubtree;//replaces node with int from smallest in right subtree
	}
}

int BiSexual::FindSmallest(TreeNode* node) { //returns integer of the smallest number in the tree or subtree taking params starting node position
	if (!IsEmpty()) {//as long as not empty
		if (node->left != nullptr) {// recursive call as long as left child != nullptr with new starting position the left child
			return FindSmallest(node->left);
		}
		else
			return node->info;//if there is no number smaller in the tree this value is the smallest in the tree, returns smallest number in tree or subtree
	}

}