class Node{
	int value;
	Node* left;
	Node* right;
	
public:
	Node();
	Node(int val);
	int getValue();
	void setValue(int val);
	void setLeft(Node* newNode);
	Node* getLeft();
	void setRight(Node* newNode);
	Node* getRight();
};
