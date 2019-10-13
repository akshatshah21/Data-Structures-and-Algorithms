#include<iostream>
using namespace std;
#define QUEUE_MAXSIZE 10
class Node {
public:
	int data;
	Node *left, *right;
	Node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

Node* q[QUEUE_MAXSIZE];
int front = 0, rear = 0, size = 0;
void enq(Node *x) {
	if(size == QUEUE_MAXSIZE) {
		cout<<"Queue full\n";
		return;
	}
	q[rear] = x;
	rear = (rear+1) % QUEUE_MAXSIZE;
	size++;
}
Node* deq() {
	if(size==0) {
		cout<<"Queue empty\n";
		return NULL;
	}
	Node *temp = q[front];
	front = (front+1) % QUEUE_MAXSIZE;
	size--;
	if(size==0) {
		front = rear = 0;
	}
	return temp;
}
Node* getFront() {
	if(size==0) {
		cout<<"Queue empty\n";
		return NULL;
	}
	return q[front];
}

void levelOrderTraversal(Node *root) {
	if(root==NULL) {
		cout<<"Root==NULL\n";
		return;
	}
	Node *trav;
	enq(root);
	while(size != 0) {
		trav = deq();
		cout<<trav->data<<' ';
		if(trav->left != NULL)
			enq(trav->left);
		if(trav->right != NULL)
			enq(trav->right);
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