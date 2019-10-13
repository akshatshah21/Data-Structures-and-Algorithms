#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node *left, *right;
	Node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

int heightOf(Node *root) {
	if(root==NULL)
		return 0;
	int l = heightOf(root->left);
	int h = heightOf(root->right);
	return (l>h ? l: h) + 1;
}

int main() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	cout<<"Height:"<<heightOf(root)<<endl;
	return 0;
}