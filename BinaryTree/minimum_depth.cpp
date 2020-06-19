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

int minimum_depth(Node *root) {
	if(!root)
		return 0;
	int l = minimum_depth(root -> left);
	int r = minimum_depth(root -> right);
	if(l == 0)
		return r+1;
	if(r == 0)
		return l+1;
	return min(l, r) + 1;
}
