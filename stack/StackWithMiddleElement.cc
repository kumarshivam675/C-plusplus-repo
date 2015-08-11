#include<iostream>

using namespace std;

class Node{
	int data;
	Node* prev;
	Node* next;
public:
	Node(int value);
	int getData();
	void setData(int value);
	void setPrev(Node* node);
	void setNext(Node* node);
	Node* getPrev();
	Node* getNext();
};

Node::Node(int value){
	data = value;
}

int Node::getData(){
	return data;
}

void Node::setData(int value){
	data = value;
}

void Node::setPrev(Node* node){
	prev = node;
}

void Node::setNext(Node* node){
	next = node;
}
Node* Node::getPrev(){
	return prev;
}
Node* Node::getNext(){
	return next;
}

class Stack{
	Node* head;
	Node* middle;
	int size;
public:
	Stack();
	void insert(int value);
	void pop();
	int getMiddle();
	void traverse();
	void deleteMiddle();
};

Stack::Stack(){
	head = NULL;
	middle = NULL;
	size = 0;
}

void Stack::insert(int value){
	Node* temp = new Node(value);
	
	if(size == 0){
		head = temp;
		middle = temp;
		size++;
		return ;
	}
	
	head->setNext(temp);
	temp->setPrev(head);
	head = temp;
	size++;
	if(size % 2 != 0){
		middle = middle->getNext();
	}
}

void Stack::pop(){
	if(size == 0)
		return ;
	Node* temp = head;
	head = head->getPrev();
	delete temp;
	size--;
	if(size == 0){
		head = NULL;
		middle = NULL;
		return ;
	}
	if(size % 2 == 0)
		middle = middle->getPrev();
}

int Stack::getMiddle(){
	return middle->getData();
}

void Stack::traverse(){
	Node* current = head;
	while(current != NULL){
		cout << current->getData() << " ";
		current = current->getPrev();
	}
	cout << endl;
}

void Stack::deleteMiddle(){
	if(size == 0)
		return ;
	Node* temp  = middle;
	Node* temp_prev = middle->getPrev();
	Node* temp_next = middle->getNext();
	temp_prev->setNext(middle->getNext());
	temp_next->setPrev(temp_prev);
	size--;
	if(size == 0){
		head = NULL;
		middle = NULL;
		return;
	}
	if(size % 2 == 0)
		middle = temp_prev;
	else
		middle = temp_prev->getNext();
	delete temp;
}



int main(){
	Stack s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(6);
	//s.insert(7);
	//s.pop();
	cout << s.getMiddle() << endl;
	s.deleteMiddle();
	cout << s.getMiddle() << endl;
	s.traverse();
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
