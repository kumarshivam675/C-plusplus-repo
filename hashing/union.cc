#include<iostream>
#include<unordered_map>

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
	void insert(int val, int pos);
	void traverse();
	void deleteNode(int pos);
	void search(int val);
	int size();
	void unionLL(Node* head1, Node* head2,LinkedList& result);
	void intersection(Node* head1,Node* head2,LinkedList &result);
};

LinkedList::LinkedList(){
	head = NULL;
}

Node* LinkedList::getHead(){
	return head;
}

int LinkedList::size(){
	int size = 0;
	Node* current = head;
	while(current != NULL){
		current = current->getNext();
		size++;
	}
	return size;
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

void LinkedList::unionLL(Node* head1, Node* head2,LinkedList &result){
	Node* temp = head1;
	unordered_map<int,int> m;
	
	while(temp != NULL){
		m[temp->getValue()] += 1;
		temp=temp->getNext();
	}
	
	temp = head2;	
	while(temp != NULL){
		m[temp->getValue()] = 1;
		temp = temp->getNext();	
	}
	
	unordered_map<int,int>::iterator it;
	int j = 0;
	for(it = m.begin(); it != m.end(); it++){
		result.insert(it->first,j);
		j++;
	}
	//cout << endl;
}

void LinkedList::intersection(Node* head1,Node* head2,LinkedList &result){
	Node* temp = head1;
	unordered_map<int,int> m;
	while(temp != NULL){
		if(m.find(temp->getValue()) == m.end())
			m[temp->getValue()] = 1;
		else 
			m[temp->getValue()] += 1;
		temp = temp->getNext();
	}
	temp = head2;
	while(temp != NULL){
		if(m.find(temp->getValue()) == m.end())
			m[temp->getValue()] = 1;
		else 
			m[temp->getValue()] += 1;
		temp = temp->getNext();
	}
	
	unordered_map<int,int>::iterator it;
	int j = 0;
	for(it = m.begin(); it != m.end(); it++){
		if(it->second > 1){
			result.insert(it->first,j);
			j++;
		}
	}
}




int main(){
	LinkedList l1,l2,result;
	l1.insert(1,0);
	l1.insert(2,1);
	l1.insert(3,2);
	l1.insert(5,3);
	//l1.traverse();
	l2.insert(1,0);
	l2.insert(2,1);
	l2.insert(3,2);
	l2.insert(6,3);
	//l2.traverse();
	//l1.unionLL(l1.getHead(),l2.getHead(),result);
	l1.intersection(l1.getHead(),l2.getHead(),result);
	result.traverse();
	return 0;
}













