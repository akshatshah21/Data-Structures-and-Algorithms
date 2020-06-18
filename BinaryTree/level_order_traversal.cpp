#include<iostream>
#include <queue>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
	Node() {
		this -> data = 0;
		left = right = NULL;
	}
	Node(int data) {
		this->data = data;
		left = right = NULL;
	}
};


void levelOrderTraversal(Node *root) {
	if(!root) {
		cout<<"Root==NULL\n";
		return;
	}
	queue<Node*> q;
	q.push(root);
	Node *trav;
	while(!q.empty()) {
		trav = q.front();
		q.pop();
		cout<<trav->data<<' ';
		if(trav->left)
			q.push(trav->left);
		if(trav->right)
			q.push(trav->right);
	}
}

int main() {
		Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);
    cout << "Level Order traversal:";
    levelOrderTraversal(root);
    cout<<endl;
    return 0;
}
