#include<iostream>

using namespace std;

class Node{
	int value;
	Node* next;
	
public:
	Node();
	Node(int val);
	int getValue();
	void setValue(int val);
	void setNext(Node* newNode);
	Node* getNext();
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

void Node::setValue(int val){
	value = val;
}

Node* Node::getNext(){
	return next;
}

void Node::setNext(Node* newnode){
	next = newnode;
}

class LinkedList{
	Node* head;
	
public:
	LinkedList();
	Node* getHead();
	void setHead(Node* node);
	void insert(int val, int pos);
	void traverse();
	void split(Node* node,Node*& a, Node*& b);
	void mergeSort(Node* &node);
	Node* merge(Node* a, Node* b);
};


LinkedList::LinkedList(){
	head = NULL;
}

void LinkedList::insert(int val, int pos){
	int k = 1;
	Node* new_node = new Node(val);
	if(head == NULL){
		head = new_node;
	}
	else if(pos == 0 && head != NULL){
		new_node->setNext(head);
		head = new_node;
	}
	
	else{
		Node* current = new Node();
		current = head;
		while(k < pos){
			current = current->getNext();
			k++;
		}
		Node* prev = new Node();
		prev = current;
		current = current->getNext();
		prev->setNext(new_node);
		if(current == NULL)
			new_node->setNext(NULL);
		else
			new_node->setNext(current);
	}
}

void LinkedList::traverse(){
	Node* current = new Node();
	current = head;
	while(current != NULL){
		cout << current->getValue() << endl;
		current = current->getNext();
	}
}

Node* LinkedList::getHead(){
	return head;
}

void LinkedList::setHead(Node* node){
	head = node;
}

void LinkedList::split(Node* node,Node*& a, Node*& b){
	Node* slow;
	Node* fast;
	if(node == NULL || node->getNext() == NULL){
		a = node;
		b = NULL;
		return ; 
	}
	slow = node;
	fast = node->getNext();
	while(fast != NULL){
		fast = fast->getNext();
		if(fast != NULL){
			slow = slow->getNext();
			fast = fast->getNext();
		}
	}
	a = node;
	b = slow->getNext();
	slow->setNext(NULL);
}

Node* LinkedList::merge(Node* a, Node* b){
	Node* result = NULL;
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	if(a->getValue() <= b->getValue()){
		result = a;
		result->setNext(merge(a->getNext(),b));
	}
	else{
		result = b;
		result->setNext(merge(a,b->getNext()));
	}
	return result;
}
		

void LinkedList::mergeSort(Node* &node){
	if(node == NULL || node->getNext() == NULL)
		return ;
	Node* a;
	Node* b;
	split(node,a,b);
	mergeSort(a);
	mergeSort(b);
	node = merge(a,b);
}

int main(){
	LinkedList l;
	l.insert(1,0);
	l.insert(5,1);
	l.insert(4,2);
	l.insert(6,3);
	l.insert(9,4);
	l.insert(7,5);
	l.traverse();
	Node* a = l.getHead();
	//cout << a->getValue();
	l.mergeSort(a);
	l.setHead(a);
	cout << "\n\n";
	l.traverse();
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
