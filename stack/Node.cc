#include"Node.h"
#include <cstddef>

using namespace std;

Node::Node(){
	next = NULL;
}

Node::Node(int val){
	value = val;
	next = NULL;
}

int Node::getValue(){
	return value;
}

void Node::setValue(int val){
	value = val;
}

Node* Node::getNext(){
	return next;
}

void Node::setNext(Node* newnode){
	next = newnode;
}

