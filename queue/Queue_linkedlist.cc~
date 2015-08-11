#include<iostream>
#include <cstddef>

using namespace std;

class Node{
	int value;
	Node* next;
public:
	Node();
	Node(int value);
	int getValue();
	Node* getNext();
	void setNext(Node* nextnode);
};

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

Node* Node:: getNext(){
	return next;
}

void Node::setNext(Node* nextnode){
	next = nextnode;
}

class Queue{
	Node* front;
	Node* rear;
	int size;
public:
	Queue();
	void enQueue(int value);
	int deQueue();
	int isEmpty();
	void traverse();
};

Queue::Queue(){
	size = 0;
	front = NULL;
	rear = NULL;
}

int Queue::isEmpty(){
	if(size == 0)
		return 1;
	else
		return 0;
}

void Queue::enQueue(int value){
	Node* newnode = new Node(value);

	if(isEmpty()){
		//cout << "adding first element\n";
		front = newnode;
		rear =  newnode;
		size++;
		return ;
	}
	rear->setNext(newnode);
	rear = newnode;
	size++;
	//cout << "size is   " << size << endl;
}

int Queue::deQueue(){
	if(isEmpty()){
		cout << "cannot deQueue\n";
		return -1;
	}
	Node* temp = front;
	int item = front->getValue();
	size--;
	if(size == 0){
		front = NULL;
		rear = NULL;
		return -1;
	}
	front = front->getNext();
	delete temp;
}

void Queue::traverse(){
	Node* current = front;
	while(current != NULL){
		cout << current->getValue() << endl;
		current = current->getNext();
	}
}

int main(){
	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);	
	q.enQueue(4);
	q.enQueue(5);
	q.deQueue();
	q.traverse();
	return 1;
}








