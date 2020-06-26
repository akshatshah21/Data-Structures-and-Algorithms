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

void insert_level_order(Node *root, int x) {
	if(!root) {
		root = new Node(x);
		return;
	}
	queue<Node*> q;
	q.push(root);
	Node *curr;
	while(!q.empty()) {
		curr = q.front();
		q.pop();
		if(curr -> left)
			q.push(curr -> left);
		else {
			curr -> left = new Node(x);
			break;
		}
		if(curr -> right)
			q.push(curr -> right);
		else {
			curr -> right = new Node(x);
			break;
		}
	}
}
