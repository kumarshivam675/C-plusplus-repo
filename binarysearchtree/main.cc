#include<iostream>
#include"BST.h"
#include"Node.h"
#include<stack>
#include<climits>

using namespace std;

int main(){
	BST b;
	b.setRoot(b.insert(b.getRoot(),5));
	b.setRoot(b.insert(b.getRoot(),2));
	b.setRoot(b.insert(b.getRoot(),8));
	b.setRoot(b.insert(b.getRoot(),3));
	b.setRoot(b.insert(b.getRoot(),11));
	b.setRoot(b.insert(b.getRoot(),7));
	b.setRoot(b.insert(b.getRoot(),1));
	//b.getRoot()->getLeft()->getRight()->setValue(1);
	//b.inOrder(b.getRoot());
	//b.search(b.getRoot(),7);
	//b.search(12);
	//cout << b.minValueNode(b.getRoot())->getValue() << endl;
	//b.setRoot(b.deleteNode(b.getRoot(),5));
	//cout << "after deleting\n";
	//b.inOrder(b.getRoot());
	//b.ksmallNode(5);
	//b.printInRange(2,8);
	//cout << "printing in range\n";
	//b.inOrder(b.getRoot());
	//cout << b.isBst(b.getRoot(),INT_MIN,INT_MAX) << endl;
	b.printVerticalOrder();
}
