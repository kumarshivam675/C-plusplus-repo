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
