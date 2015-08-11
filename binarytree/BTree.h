#include<string>

class Node;

class BTree{
	Node* root;
	
public:
    BTree();
    void addChild(Node* root, std::string, int value);
    Node* getRoot();
    void preOrder(Node* root);
    int size(Node* head);
    int maxHeight(Node* head);
    void deleteTree(Node* head);
    int pathSum(Node* node,int value);
    void levelOrder();
    void printLevelOrder(Node* node, int level);
    void rootToLeaf();
    void printRootToLeaf(Node* node, int path[],int pathlen);
    void printPath(int path[],int pathlen);
    void levelOrderWidth();
    int printLevelOrderWidth(Node* node, int level);
};
