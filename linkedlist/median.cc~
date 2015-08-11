#include<iostream>
#include<iomanip>

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
	Node* middle;
	int size;
	
public:
	LinkedList();
	Node* getHead();
	Node* getMiddle();
	int getSize();
	void insert(int val);
	void traverse();
};

LinkedList::LinkedList(){
	head = NULL;
	middle = NULL;
	size = 0;
}
void LinkedList::insert(int val){
	int k = 1;
	Node* new_node = new Node(val);
	if(head == NULL){
		head = new_node;
		middle = head;
		size = 1;
		return ;
	}
	Node* current = head;
	while(current->getNext() != NULL && current->getNext()->getValue() < val){
		current = current->getNext();
	}
	if(current == head && head->getValue() > val){
		new_node->setNext(head);
		head = new_node;
		middle = head;
		size++;
		return ;
	}
	Node* temp = current->getNext();
	current->setNext(new_node);
	new_node->setNext(temp);
	size++;
	
	if(size%2 != 0)
		middle = middle->getNext();
}

int LinkedList::getSize(){
	return size;
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

Node* LinkedList::getMiddle(){
	return middle;
}

int main(){
	LinkedList l;
	int input,value;
	cin >> input;
	for(int i = 0; i < input; i++){
		cin >> value;
		l.insert(value);
		if(l.getSize()%2 == 0){
			cout << fixed << setprecision(1) << float(l.getMiddle()->getValue() + l.getMiddle()->getNext()->getValue())/2 << endl;
		}
		else
			cout << fixed << setprecision(1) << float(l.getMiddle()->getValue()) << endl;
	}
	return 0;
}
