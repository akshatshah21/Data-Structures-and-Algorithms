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

void postorder(Node *root) {
	if(!root)
		return;
	postorder(root -> left);
	postorder(root -> right);
	cout << root -> data << " ";
}
