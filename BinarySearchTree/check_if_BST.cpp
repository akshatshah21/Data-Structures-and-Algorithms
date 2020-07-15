#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
	Node() {
		left = right = NULL;
		data = 0;
	}
	Node(int data) {
		this -> data = data;
		left = right = NULL;
	}
};

bool isBST(Node *root, Node *l=nullptr, Node *h=nullptr) {
	if(!root)
		return true;
	if(l && l->data >= root->data)
		return false;
	if(h && h->data <= root->data)
		return false;
	return isBST(root->left, l, root) && isBST(root->right, root, h);
}
