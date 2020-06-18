#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
	Node() {
		this -> data = 0;
		left = right = NULL;
	}
	Node(int data) {
		this -> data = data;
		left = right = NULL;
	}
};

int height(Node *root) {
	if(!root)
		return 0;
	int l = height(root -> left);
	int r = height(root -> right);
	return max(l, r) + 1;
}

// Root at level 1
void print_level(Node *root, int level) {
	if(!root)
		return;
	if(level == 1)
		cout << root -> data << " ";
	else {
		print_level(root -> left, level-1);
		print_level(root -> right, level-1);
	}
}

// Recursive Level Order using print_level
void level_order(Node *root) {
	int h = height(root);
	for(int i=1;i<=h;i++) {
		print_level(root, i);
	}
}

