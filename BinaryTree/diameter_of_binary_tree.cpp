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

int diameter_util(Node* root, int &maxd) {
	if(!root)
		return 0;
	int l = diameter_util(root -> left, maxd);
	int r = diameter_util(root -> right, maxd);
	maxd = max(maxd, l+r+1);
	return max(l,r) + 1;
}

int diameter(Node *root) {
	if(!root)
		return 0;
	int maxd = 0;
	diameter_util(root, maxd);
	return maxd;
}
