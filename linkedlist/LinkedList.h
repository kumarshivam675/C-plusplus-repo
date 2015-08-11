class Node;

class LinkedList{
	Node* head;
	
public:
	LinkedList();
	Node* getHead();
	void insert(int val, int pos);
	void traverse();
	void deleteNode(int pos);
	void search(int val);
	void reverse();
	Node* mergesort(Node* head);
	Node* merge(Node* a, Node* b);
};
