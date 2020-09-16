#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node *left, *right;
	Node(int data) {
		this -> data = data;
		this -> left = NULL;
		this -> right = NULL;
	}
};

int search(int arr[], int l, int h, int x) {
	int i;
	for(i=l;i<=h;i++) {
		if(arr[i] == x)	break;
	}
	return i;
}

Node* _build(int pre[], int post[], int *preIndex, int postStart, int postEnd, int size) {
	if(*preIndex >= size || postStart > postEnd) // Base Case
		return NULL;
	Node *node = new Node(pre[(*preIndex)++]);
	if(postStart == postEnd) // No child
		return node;
	int postIndex = search(post, postStart, postEnd, pre[*preIndex]); // Note the key
	if(postIndex <= postEnd){
		node->left = _build(pre, post, preIndex, postStart, postIndex, size);
		node->right = _build(pre, post, preIndex, postIndex+1, postEnd, size);
	}
	return node;
} 

Node* build(int pre[], int post[], int size) {
	int preIndex = 0;
	return _build(pre, post, &preIndex, 0, size-1, size);
}

void printInorder(Node *root) {
	if(root==NULL)
		return;
	printInorder(root->left);
	cout<<root->data<<' ';
	printInorder(root->right);
	return;
}

int main() {
	int n;
	cout<<"Enter number of nodes:";
	cin>>n;
	int pre[n], post[n];
	cout<<"Enter preorder sequence:";
	for(int i=0;i<n;i++)
		cin>>pre[i];
	cout<<"Enter postorder sequence:";
	for(int i=0;i<n;i++)
		cin>>post[i];
	Node *root = build(pre, post, n);
	cout<<"Constructed binary tree:";
	printInorder(root);
	cout<<endl;
	return 0;
}