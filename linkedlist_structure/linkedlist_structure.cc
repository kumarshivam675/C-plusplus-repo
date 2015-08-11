#include<iostream>

struct Node{
	int data;
	struct Node *next;
	
	Node* insert(Node* head, int data){
		Node* newnode = new Node();
		newnode->data = data;
		newnode->next = NULL;
		if(head == NULL){
			return newnode;
		}
		Node* temp = new Node();
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newnode;
		return head;
	}
	
	void traverse(Node* head){
		Node* temp = new Node();
		temp = head;
		while(temp != NULL){
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}
};

int main(){
	Node l;
	Node *head = NULL;
	head = l.insert(head,3);
	head = l.insert(head,5);
	l.traverse(head);
	return 1;
}
