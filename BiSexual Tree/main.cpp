#include "BiSexual.h"



int main() {
	BiSexual tree1;
	tree1.BPutItem(5);
	//tree1.BPutItem(2);
	//tree1.BPutItem(3);
	//tree1.BPutItem(8);
	//tree1.BPutItem(12);
	//tree1.BPutItem(10);
	//tree1.BPutItem(7);
	//tree1.BPutItem(6);
	//tree1.BPutItem(15);
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
	tree1.MakeEmptyPublic();
	tree1.printTree();
	return 0;
}