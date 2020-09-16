#include<iostream>
#include<queue>
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

void print_reverse_level_order(Node *root) {
	if(root) {
		queue<Node*> q;
		stack<int> s;
		Node *curr;
		q.push(root);
		while(!q.empty()) {
			curr = q.front();
			q.pop();
			s.push(curr -> data);

			if(curr -> right)
				q.push(curr -> right);
			if(curr -> left)
				q.push(curr -> left);
		}
		while(!s.empty()) {
			cout << s.top() << " ";
			s.pop();
		}
	}
}

