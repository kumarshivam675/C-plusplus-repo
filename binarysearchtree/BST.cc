#include "BST.h"
#include "Node.h"
#include<iostream>
#include<cstddef>
#include<stack>
#include<vector>
#include<map>

using namespace std;


BST::BST(){
	root = NULL;
}

Node* BST::insert(Node* node,int value){
	if(node == NULL){
		Node* newNode = new Node(value);
		return newNode;
	}
	else if(value < node->getValue())
		node->setLeft(insert(node->getLeft(),value));
	else if(value > node->getValue())
		node->setRight(insert(node->getRight(),value));
		
	return node;
}

void BST::setRoot(Node* node){
	root = node;
}

Node* BST::getRoot(){
	return root;
}

void BST::inOrder(Node* node){
	if(node == NULL)
		return ;
	inOrder(node->getLeft());
	cout << node->getValue() << endl;
	inOrder(node->getRight());
}

void BST::search(int value){
	int flag = searchNode(root,value);
	if(flag == -1)
		cout << "element not found\n";
	else
		cout << "element found\n";
}
	
int BST::searchNode(Node* node,int value){
	if(node->getValue() == value)
		return value;
	else if (value < node->getValue()){
		if(node->getLeft() == NULL)
			return -1;
		else
			return searchNode(node->getLeft(),value);
	}
	else if (value > node->getValue()){
		if(node->getRight() == NULL)
			return -1;
		else
			return searchNode(node->getRight(),value);
	}
}

bool BST::isLeaf(Node* node){
	if(node->getLeft() == NULL && node->getRight() == NULL)
		return true;
	else
		return false;
}

Node* BST::minValueNode(Node* node){
	Node* current = node;
	while(current->getLeft() != NULL)
		current = current->getLeft();
	return current;
}

Node* BST::deleteNode(Node* node,int value){
	if(node == NULL)
		return node;
	else if(value < node->getValue()){
		node->setLeft(deleteNode(node->getLeft(),value));
	}
	
	else if(value > node->getValue()){
		node->setRight(deleteNode(node->getRight(),value));
	}
	
	else{
		//cout <<"hello   " << node->getValue() << endl;
		if(node->getLeft() == NULL){
			Node* temp = node->getRight();
			delete node;
			return temp;
		}
		else if(node->getRight() == NULL){
			Node* temp = node->getLeft();
			delete node;
			return temp;
		}
		
		Node* minValue = minValueNode(node->getRight());
		//cout << "minValue is " << minValue->getValue() << endl;
		node->setValue(minValue->getValue());
		node->setRight(deleteNode(node->getRight(),minValue->getValue()));
	}
	return node;
}

void BST::ksmallNode(int k){
	stack<int> s;
	int flag = 0;
	kthsmall(root,s,flag,k);
	cout << "kth smallest element is " << s.top() << endl;
}

void BST::kthsmall(Node* node, stack<int> &s, int &flag,int k){
	if(node == NULL)
		return ;
	kthsmall(node->getLeft(),s,flag,k);
	if(s.size() == k)
		return ;
	s.push(node->getValue());
	kthsmall(node->getRight(),s,flag,k);
}

void BST::printInRange(int min, int max){
	root = printInRangeRecur(root,min,max);
}

Node* BST::printInRangeRecur(Node* node, int min, int max){
	if(node == NULL)
		return node;
	node->setLeft(printInRangeRecur(node->getLeft(),min,max));
	node->setRight(printInRangeRecur(node->getRight(),min,max));
	
	if(node->getValue() < min || node->getValue() > max){
		if(node->getLeft() == NULL){
			Node* temp = node->getRight();
			delete node;
			return temp;
		}
		else if(node->getRight() == NULL){
			Node* temp = node->getLeft();
			delete node;
			return temp;
		}
	}
	return node;
}

int BST::isBst(Node* node, int min, int max){
	if(node == NULL)
		return 1;
	if(node->getValue() < min || node->getValue() > max)
		return 0;
		
	return isBst(node->getLeft(),min, node->getValue() -1) && isBst(node->getRight(),node->getValue() + 1,max);
}

void BST::verticalOrderRecur(Node* node,int hd, map<int, vector<int> > &m){
	if(node == NULL)
		return ;
	verticalOrderRecur(node->getLeft(),hd - 1,m);
	verticalOrderRecur(node->getRight(),hd + 1,m);
	m[hd].push_back(node->getValue());
}


void BST::printVerticalOrder(){
	map<int, vector<int> > m;
	verticalOrderRecur(root,0,m);
	map<int,vector<int> >::iterator it;
	for(it = m.begin(); it != m.end(); it++){
		for(int i = 0; i < it->second.size();i++){
			cout<<it->second[i] << "  ";
		}
		cout << endl;
	}
}
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
