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

void delete_util(Node *root, Node *to_del) {
	if(!root)
		return;
	queue<Node*> q;
	q.push(root);
	Node *curr;
	while(!q.empty()) {
		curr = q.front();
		q.pop();

		if(curr == to_del) {
			curr = NULL;
			delete to_del;
			return;
		}
		if(curr -> left) {
			if(curr -> left == to_del) {
				curr -> left = NULL;
				delete to_del;
				return;
			} 
			else
				q.push(curr -> left);
		}
		if(curr -> right) {
			if(curr -> right == to_del) {
				curr -> right = NULL;
				delete to_del;
				return;
			} 
			else
				q.push(curr -> right);
		}
	}
}


void delete_level_order(Node *root, int key) {
	if(!root)
		return;
	queue<Node*> q;
	q.push(root);
	Node *curr, *to_del;
	while(!q.empty()) {
		curr = q.front();
		q.pop();
		
		if(curr -> data == key)
			to_del = curr;

		if(curr -> left)
			q.push(curr -> left);
		if(curr -> right)
			q.push(curr -> right);
	}
	if(!to_del)
		return;
	to_del -> data = curr -> data;
	delete_util(root, curr);
}
