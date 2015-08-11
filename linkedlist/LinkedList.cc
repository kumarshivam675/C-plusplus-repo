#include"LinkedList.h"
#include"Node.h"

#include<iostream>
#include<cstdlib>
#include<cstddef>

using namespace std;

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

void LinkedList::deleteNode(int pos){
	int k = 1;
	if(pos == 0){
		Node* current = new Node();
		current = head;
		head = head->getNext();
		delete current;
	}
		
	else{
		Node* current = new Node();
		Node* nextNode = new Node();
		current = head;
		Node* prev = new Node();
		while(k < pos){
			current = current->getNext();
			k++;
		}
		prev = current;
		current = current->getNext();
		nextNode = current->getNext();
		if(current == NULL)
			prev->setNext(NULL);
		else
			prev->setNext(nextNode);
		
		delete current;
	}
}

void LinkedList::search(int val){
	int pos = 0;
	Node* current = new Node();
	current = head;
	while(current != NULL){
		if(current->getValue() == val){
			cout << "found at position: " << pos << endl;
			break;
		}
		current = current->getNext();
		pos++;
	}
}

void LinkedList::reverse(){
	cout << "reverse\n";
	Node* nextNode = new Node();
	Node* prev = new Node();
	prev = NULL;
	while(head != NULL){
		nextNode = head->getNext();
		head->setNext(prev);
		prev = head;
		head = nextNode;
	}
	head = prev;
	
	//cout << head->getValue() << endl;
}

Node* LinkedList::getHead(){
	return head;
}

Node* LinkedList::mergesort(Node* headref){
	if(headref == NULL)
		return NULL;
	else if(headref->getNext() == NULL)
		return NULL;
	else{
		int i = 1;
		Node* slowptr = new Node();
		Node* fastptr = new Node();
		slowptr = headref;
		fastptr = headref->getNext();
		while(fastptr->getNext() != NULL){
			i++;
			fastptr = fastptr->getNext();
			if(i % 2 == 0)
				slowptr = slowptr->getNext();
		}
		Node* temp = new Node();
		temp = slowptr->getNext();
		slowptr->setNext(NULL);
		cout << "head " << headref->getValue() << endl;
		cout << "middle element " << temp->getValue() << endl;
		Node* newhead = mergesort(headref);
		Node* newtemp = mergesort(temp);
		//cout << "merging now\n";
		return merge(newhead,temp);
		//traverse();

	}
}

Node* LinkedList::merge(Node* a, Node* b){
	cout << "value of a and b " << a->getValue() << "  " << b->getValue() << endl;
	Node* headref = new Node();
	if(a->getValue() < b->getValue()){
		headref = a;
		a = a->getNext();
		cout << "a is small\n";
	}
	else if(b->getValue() < a->getValue()){
		headref = b;
		b = b->getNext();
	}
	
	if(a == NULL){
		headref->setNext(b);
		//cout << "headref ke next ka value " << headref->getNext()->getValue() << endl;
		b = NULL;
		//cout << "headref ke next ka value after b in NULL " << headref->getNext()->getValue() << endl;
		cout << "a is NULL\n";
	}
	
	else if(b == NULL){
		headref->setNext(a);
		a = NULL;
	}
		
	//cout << "before while\n";
	while(a != NULL || b != NULL){
		cout << "in the while\n";
		if(a == NULL){
			headref->setNext(b);
			//cout << "a is NULL\n";	
			break;
		}
		if(b == NULL){
			headref->setNext(a);
			break;
		}
		else if(a->getValue() < b->getValue()){
			headref->setNext(a);
			a = a->getNext();
		}
		else{
			headref->setNext(b);
			b = b->getNext();
		}
	}
	//cout << "time to exit merge\n";
	return headref;
}











	

