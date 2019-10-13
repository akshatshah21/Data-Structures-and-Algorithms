#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node *left, *right;
	Node (int data) {
		this->data = data;
	}
};

int search(int arr[], int l, int h, int x) {
	int i;
	for(i=l;i<=h;i++) {
		if(arr[i] == x)	break;
	}
	return i;
}

Node* _build(int in[], int post[], int inStart, int inEnd, int *postIndex) {
	if(inStart > inEnd)	// Base Case
		return NULL;
	Node *node = new Node(post[(*postIndex)--]);
	if(inStart == inEnd) // No child
		return node;
	int inIndex = search(in, inStart, inEnd, node->data);
	node->right = _build(in, post, inIndex+1, inEnd, postIndex);
	node->left = _build(in, post, inStart, inIndex-1, postIndex);
	return node;
}

Node* build(int in[], int post[], int inStart, int inEnd) {
	int postIndex = inEnd;
	return _build(in, post, inStart, inEnd, &postIndex);
}

void printInorder(Node *root) {
	if(root == NULL)	return;
	printInorder(root->left);
	cout<<root->data<<' ';
	printInorder(root->right);
}

int main() {
	int n;
	cout<<"Enter number of nodes:";
	cin>>n;
	int in[n], post[n];
	cout<<"Enter inorder sequence:";
	for(int i=0;i<n;i++)	cin>>in[i];
	cout<<"Enter postorder sequence:";
	for(int i=0;i<n;i++)	cin>>post[i];
	Node *root = build(in, post, 0, n-1);
	cout<<"Constructed binary tree:";
	printInorder(root);
	cout<<endl;
	return 0;
}