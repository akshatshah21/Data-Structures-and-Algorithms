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

// Logic: If we reverse preorder traversal of (Root->Right->Left) (note: right before left)
// we get postorder traversal (Left->Right->Root)
// So the code is very similar to iterative preorder, only note the order of pushing children
// to stack, and reversing the sequence at the end. For reversing, we use another stack

void postorder(Node *root) {
	if(!root)
		return;
	stack<Node*> st;
	stack<int> rev;
	st.push(root);
	Node *curr;
	while(!st.empty()) {
		curr = st.top();
		st.pop();

		rev.push(curr->data);
		// Left pushed first, then right | (Root->Right->Left)
		if(curr -> left)
			st.push(curr -> left);
		if(curr-> right)
			st.push(curr -> right);
	}

	// Reversing the sequence to get postorder
	while(!rev.empty()) {
		cout << rev.top() << " ";
		rev.pop();
	}
}

// Better space complexity: Just like in preorder, we printed left children
// and pushed right children to stack, we left children to stack st (and push
// right children to rev)

void better_postorder(Node *root) {
	if(!root)
		return;
	stack<Node*> st;
	stack<int> rev;
	Node *curr = root;
	while(!st.empty() || curr) {
		while(curr) {
			rev.push(curr -> data);
			if(curr -> left)
				st.push(curr -> left);
			curr = curr -> right;
		}
		if(!st.empty()) {
			curr = st.top();
			st.pop();
		}
	}

	// Reversing
	while(!rev.empty()) {
		cout << rev.top() << " ";
		rev.pop();
	}
}
