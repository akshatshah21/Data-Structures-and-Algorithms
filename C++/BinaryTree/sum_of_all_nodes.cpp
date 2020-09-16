#include<queue>

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

int sum_recursive(Node* root) {
	if(!root)
		return 0;
	int l = sum_BT(root -> left);
	int r = sum_BT(root -> right);
	return l + r + root -> data;
}

// Uses level order traversal
int sum_iterative(Node* root) {
	if(!root)
		return 0;
	int sum = 0;
	queue<Node*> q;
	q.push(root);
	Node* curr;
	while(!q.empty()) {
		curr = q.front();
		q.pop();
		sum += curr -> data;
		if(curr -> left)
			q.push(curr -> left);
		if(curr -> right)
			q.push(curr -> right);
	}
	return sum;
}
