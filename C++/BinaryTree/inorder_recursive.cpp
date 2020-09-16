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

void inorder(Node *root) {
	if(!root)
		return;
	inorder(root -> left);
	cout << root -> data << " ";
	inorder(root -> right);
}
