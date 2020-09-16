#include<iostream>
#include<queue>
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

void left_view(Node *root) {
	if(!root)
		return;
	queue<Node*> q;
	q.push(root);
	Node *curr;
	int this_level, next_level=1;
	while(!q.empty()) {
		this_level = next_level - 1;
		curr = q.front();
		q.pop();
		cout << curr -> data << " ";
		if(curr -> left) {
			q.push(curr -> left);
			next_level++;
		}
		if(curr -> right) {
			q.push(curr -> right);
			next_level++;
		}
		for(int i=0;i<this_level;i++) {
			curr = q.front();
			q.pop();
			if(curr -> left) {
				q.push(curr -> left);
				next_level++;
			}
			if(curr -> right) {
				q.push(curr -> right);
				next_level++;
			}
		}
	}
}
