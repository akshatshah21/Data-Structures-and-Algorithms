#include<iostream>
#include<queue>
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

void print_right_view(Node *root) {
	if(root) {
		queue<Node*> q;
		q.push(root);
		Node *curr;
		int this_level, next_level = 1;
		while(!q.empty()) {
			this_level = next_level-1;
			next_level = 0;
			curr = q.front();
			q.pop();
			cout << curr -> data << " ";
			if(curr -> right) { // note: right before left
				q.push(curr -> right);
				next_level++;
			}
			if(curr -> left) {
				q.push(curr -> left);
				next_level++;
			}
			while(this_level--) {
				curr = q.front();
				q.pop();
				if(curr -> right) {
					q.push(curr -> right);
					next_level++;
				}
				if(curr -> left) {
					q.push(curr -> left);
					next_level++;
				}
			}
		}
	}
}
