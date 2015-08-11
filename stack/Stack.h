class Node;

class Stack{
	Node* top;
	int size;
	
public:
    Stack();
    void push(int val);
    int pop();
    void traverse();
    void nextGreaterElement(int a[], int size);
    int isEmpty();
    void span(int a[], int size);
    int getSize();
};
