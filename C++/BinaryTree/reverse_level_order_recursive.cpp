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

int height(Node *root) {
	if(!root)
		return 0;
	int l = height(root -> left);
	int r = height(root -> right);
	return max(l, r) + 1;
}

void print_level(Node *root, int level) {
	if(root) {
		if(level == 1)
			cout << root -> data << " ";
		else {
			print_level(root -> left, level-1);
			print_level(root -> right, level-1);
		}
	}
}

void print_level_order_reverse(Node *root) {
	if(root) {
		int h = height(root);
		for(int i=h;i>0;i--) {
			print_level(root, i);
		}
	}
}
