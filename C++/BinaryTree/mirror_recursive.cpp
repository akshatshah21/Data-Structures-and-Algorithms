// LeetCode: https://leetcode.com/problems/invert-binary-tree/
// GFG Practice: https://practice.geeksforgeeks.org/problems/mirror-tree/1
#include <algorithm>
using namespace std;
class Node {
public:
	int data;
	Node *left, *right;
	Node() {
		left = right = nullptr;
		data = 0;
	}
	Node(int data) {
		this -> data = data;
		left = right = nullptr;
	}
};

void mirror(Node *root) {
	if(root) {
		mirror(root -> left);
		mirror(root -> right);
		swap(root -> left, root -> right);
	}
}

// In fact, even the functions below should be valid. Think about it

void mirror2(Node *root) {
	if(root) {
		swap(root->left, root->right);
		mirror2(root->left);
		mirror2(root->right);
	}
}


void mirror3(Node *root) {
	if(root) {
		mirror3(root -> left);
		swap(root->left, root->right);
		mirror3(root->left); // note this
	}
}

// This is like applying the mirror function in different orders of traversal
