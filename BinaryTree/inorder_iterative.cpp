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

void inorder(Node *root) {
	if(!root)
		return;
	stack<Node*> st;
	Node *curr = root;
	while(!st.empty() || curr) {
		while(curr) {
			st.push(curr);
			curr = curr -> left;
		}
		curr = st.top();
		st.pop();
		cout << curr -> data << " ";
		curr = curr -> right;
	}
}
