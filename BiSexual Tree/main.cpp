///////////////////////////////////////////////////////////
//Daniel Dooley											 //
//Mr. Busch												 //
//Lab 5 - Bisexual tree.... binary....					 //
//"Create a binary tree class which will take integers	 //
//and sort them in alphabetical order. Your class should //
//also be able to sort them in reverse alphabetical order//
//as well."												 //
///////////////////////////////////////////////////////////

#include "BiSexual.h"

int main() {
	BiSexual tree1; //creates tree1 object of BiSexual class
	tree1.BPutItem(5);//inserts 5 into tree
	tree1.BPutItem(2);
	tree1.BPutItem(3);
	tree1.BPutItem(8);
	tree1.BPutItem(12);
	tree1.BPutItem(10);
	tree1.BPutItem(7);
	tree1.BPutItem(6);
	tree1.BPutItem(15);
	tree1.BPutItem(1);
	//tree1.printTree();
	tree1.printAscending();
	cout << endl;
	tree1.printDescending();
	cout << endl;
	tree1.printTree();
	//cout<< "Smallest: " << tree1.FindSmallestPublic();
	//tree1.DeleteNum(8);
	//tree1.DeleteNum(5);
	//tree1.DeleteNum(7);
	//tree1.DeleteNum(3);
	tree1.printAscending();
	cout << endl;
	tree1.printDescending();
	cout << endl;
	tree1.printTree();
	//////////////////////////////////////////////////////
	//	Warning you cannot call makeempty twice because //
	//it will try to delete something that doesnt exist //
	//////////////////////////////////////////////////////
	//tree1.MakeEmptyPublic(); 
	return 0;
}