#include<algorithm>
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

// A binary tree is balanced if absolute difference of the heights of
// the left and right subtrees is not more than 1, for every node in the tree;

int height_util(Node *root, bool &b) {
	if(!root)
		return 0;
	int l = height_util(root -> left, b);
	int r = height_util(root -> right, b);
	if(abs(l-r) > 1)
		b = 0;
	return max(l, r) + 1;
}

bool is_balanced(Node *root) {
	if(!root)
		return true;
	bool b = true;
	height_util(root, b);
	return b;
}
