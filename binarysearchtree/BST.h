#include<stack>
#include<map>
#include<vector>

class Node;

class BST{
	Node* root;
public:
	BST();
	Node* getRoot();
	void setRoot(Node* node);
	Node* insert(Node* node,int value);
	void inOrder(Node* node);
	void search(int value);
	int searchNode(Node* node, int value);
	Node* deleteNode(Node* node, int value);
	Node* minValueNode(Node* node);
	bool isLeaf(Node* node);
	void ksmallNode(int k);
	void kthsmall(Node* node, std::stack<int> &s, int &flag, int k);
	void printInRange(int min, int max);
	Node* printInRangeRecur(Node* node, int min, int max);
	int isBst(Node* node,int min,int max);
	void printVerticalOrder();
	void verticalOrderRecur(Node* root,int hd,std::map<int,std::vector<int> > &m);
};
