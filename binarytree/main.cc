#include<iostream>
//#include<string>

#include"Node.h"
#include"BTree.h"

using namespace std;


int main(){
	BTree t;
	t.addChild(t.getRoot(),"left",1);
	t.addChild(t.getRoot(),"left", 2);
	t.addChild(t.getRoot(),"right", 3);
	t.addChild(t.getRoot()->getLeft(),"left", 4);
	t.addChild(t.getRoot()->getLeft(),"right", 5);
	t.addChild(t.getRoot()->getRight(),"left", 6);
	//t.addChild(t.getRoot()->getRight(),"right", 7);
	/*t.preOrder(t.getRoot());
	int size = t.size(t.getRoot());
	cout << "size " << size << endl;
	int height = t.maxHeight(t.getRoot());
	cout << "height " << height << endl;
	t.deleteTree(t.getRoot());
	cout << t.getRoot()->getValue() << endl;
	int flag = t.pathSum(t.getRoot(),9);
	cout << flag << endl;*/
	//t.levelOrder();
	//t.rootToLeaf();
	t.levelOrderWidth();
	return 0;
}
