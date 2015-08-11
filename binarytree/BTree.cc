#include<iostream>
#include<string>
#include<cstddef>

#include"BTree.h"
#include"Node.h"

using namespace std;

BTree::BTree(){
	root = NULL;
}

Node* BTree::getRoot(){
	return root;
}

void BTree::addChild(Node* node,string dir, int value){
	Node* newNode = new Node(value);
	if(node == NULL){
		root = newNode;
		//cout <<"root is null\n";
	}
	else if(dir == "left"){
		node->setLeft(newNode);
		//cout <<"root is set to left\n";
	}
	else if(dir == "right"){
		node->setRight(newNode);
		//cout <<"root is set to rigth\n";
	}
}

void BTree:: preOrder(Node* head){
	if(head == NULL)
		return ;
	cout << head->getValue() << endl;
	preOrder(head->getLeft());
	preOrder(head->getRight());
}

int BTree:: size(Node* head){
	if(head == NULL)
		return 0;
	else
		return (size(head->getLeft()) + 1 + size(head->getRight()));
}

int BTree::maxHeight(Node* head){
	if(head == NULL)
		return 0;
	else{
		int lHeight = maxHeight(head->getLeft());
		int rHeight = maxHeight(head->getRight());
		
		if(lHeight > rHeight)
			return lHeight + 1;
		else
			return rHeight + 1;
	}
}

void BTree::deleteTree(Node* node)
{
    if (node == NULL) return;
 
    /* first delete both subtrees */
    deleteTree(node->getLeft());
    deleteTree(node->getRight());
   
    /* then delete the node */
    cout << " Deleting node:" <<  node->getValue() << endl;
    delete node;
} 

int BTree::pathSum(Node* node,int sum){
	if(node == NULL)
		return 0;
	else{
		int lpath = 0, rpath = 0;
	
		if(node->getLeft() == NULL && node->getRight() == NULL){
			return (node->getValue() == sum);
		}
		int new_value = sum - node->getValue();
		if(node->getLeft() != NULL){
			lpath = pathSum(node->getLeft(),new_value);
		}
		if(node->getRight() != NULL){
			rpath = pathSum(node->getRight(),new_value);
		}
		return lpath || rpath;
	}
}


void BTree::levelOrder(){
	int height = maxHeight(root);
	for(int i = 1; i <= height; i++){
		printLevelOrder(root,i);
		cout << "\n";
	}
}

void BTree::printLevelOrder(Node* node, int level){
	if(node == NULL)
		return ;
	if(level == 1){
		cout << node->getValue() << " ";
		return ;
	}
	else{
		printLevelOrder(node->getLeft(),level-1);
		printLevelOrder(node->getRight(),level-1);
	}
}

void BTree::rootToLeaf(){
	int path[1000],pathlen = 0;
	printRootToLeaf(root,path,pathlen);
}

void BTree::printRootToLeaf(Node* node, int path[],int pathlen){
	if(node == NULL){
		return ;
	}
	path[pathlen] = node->getValue();
	pathlen++;
	if(node->getLeft() == NULL && node->getRight() == NULL)
		printPath(path,pathlen);
	else{
		printRootToLeaf(node->getLeft(),path,pathlen);
		printRootToLeaf(node->getRight(),path,pathlen);
	}
}

void BTree::printPath(int path[],int pathlen){
	for(int i = 0; i < pathlen;i++){
		cout << path[i] << " ";
	}
	cout << endl;
}

void BTree::levelOrderWidth(){
	int height = maxHeight(root);
	int value[10],max = 0;
	for(int i = 1; i <= height; i++){
		value[i] = printLevelOrderWidth(root,i);
		if(max < value[i])
			max = value[i];
		//cout << value[i] << "\n";
	}
	cout << max << "\n";
}

int BTree::printLevelOrderWidth(Node* node, int level){
	if(node == NULL)
		return 0;
	if(level == 1){
		//cout << node->getValue() << " ";
		return 1;
	}
	else{
		int left = printLevelOrderWidth(node->getLeft(),level-1);
		int right = printLevelOrderWidth(node->getRight(),level-1);
		return left + right;
	}
}
		










	
