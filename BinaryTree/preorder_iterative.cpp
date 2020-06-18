#include<iostream>
#include<stack>
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

void preorder(Node *root) {
	if(!root)
		return;
	stack<Node*> st;
	st.push(root);
	Node *curr;
	while(!st.empty()) {
		curr = st.top();
		st.pop();
		cout << curr -> data << " ";
		// First right, then left
		if(curr -> right)
			st.push(curr -> right);
		if(curr -> left)
			st.push(curr -> left);
	}
}

// Better space complexity, stores only right children, prints left children directly
void better_preorder(Node *root) {
	if(!root)
		return;
	stack<Node*> st;
	Node* curr = root;
	while(curr || !st.empty()) {
		while(curr) {
			cout << curr << " ";
			if(curr -> right)
				st.push(curr -> right);
			curr = curr -> left;
		}
		if(!st.empty()) {
			curr = st.top();
			st.pop();
		}
	}
}
