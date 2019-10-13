#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node *left, *right;
	Node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

int search(int arr[], int l, int h, int x) {
	int i;
	for(i=l;i<=h;i++) {
		if(arr[i] == x)	break;
	}
	return i;
}

Node* build(int in[], int pre[], int inStart, int inEnd) {
	static int preIndex = 0;
	if(inStart > inEnd) // Base Case
		return NULL;

	Node *node = new Node(pre[preIndex++]);

	if(inStart == inEnd) // No child
		return node;

	int inIndex = search(in, inStart, inEnd, node->data);
	node->left = build(in, pre, inStart, inIndex-1);
	node->right = build(in, pre, inIndex+1, inEnd);
	return node;
}

void printInorder(Node *root) {
	if(root==NULL) 
		return;
	printInorder(root->left);
	cout<<root->data<<' ';
	printInorder(root->right);
}


int main() {
	int n;
	cout<<"Number of nodes:";
	cin>>n;
	int in[n], pre[n];
	cout<<"Enter inorder sequence:";
	for(int i=0;i<n;i++)	cin>>in[i];
	cout<<"Enter preorder sequence:";
	for(int i=0;i<n;i++)	cin>>pre[i];
	Node *root = build(in, pre, 0, n-1);
	cout<<"Constructed binary tree:";
	printInorder(root);
	cout<<endl;
	return 0;	
}
