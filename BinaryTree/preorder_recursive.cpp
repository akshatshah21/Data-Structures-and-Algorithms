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

void preorder(Node *root) {
	if(!root)
		return;
	cout << root -> data << " ";
	preorder(root -> left);
	preorder(root -> right);
}
