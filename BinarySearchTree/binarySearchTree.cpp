#include<iostream>
using namespace std;
template<class T>
class BST {
private:
	class BSTNode {
	public:
		T data;
		BSTNode *left, *right;

		BSTNode(T x, BSTNode *left=NULL, BSTNode *right=NULL) {
			this.left = left;
			this.right = right;
			data = x;
		}
	};

	BSTNode* insert(BSTNode* root, T x);
	void preorder(BSTNode *root);
	void inorder(BSTNode *root);
	void postorder(BSTNode *root);
public:
	BSTNode<T> *root;
	bool contains(T x);
	void insert(T x);
	void printPreorder();
	void printInorder();
	void printPostorder();
};

template<class T>
bool BST<T>::contains(T x) {
	if(root == NULL)
		return false;
	BSTNode<T> *trav = root;
	while(root != NULL) {
		if(x < trav -> data)	trav = trav -> left;
		else if(x > trav -> data)	trav = trav -> right;
		else	return true;
	}
	return false;
}

template<class T>
void BST<T>::insert(T x) {
	root = insert(root, x);
}

template<class T>
BSTNode* BST<T>::insert(BSTNode* root, T x) {
	if(root == NULL)
		root = new Node(x);
	else if(x < root -> data)
		root -> left = insert(root -> left, x);
	else if(x > root -> data)
		root -> right = insert(root -> right, x);
	return root;
}

template<class T>
void BST<T>::printPreorder() {
	preorder(root);
	cout << endl;
}

template<class T>
void BST<T>::printInorder() {
	inorder(root);
	cout << endl;
}

template<class T>
void BST<T>::printPostorder() {
	postorder(root);
	cout << endl;
}

/* void BST::printLevelorder() { */
/* 	inorder(root); */
/* 	cout << endl; */
/* } */


template<class T>
void BST::preorder(BSTNode *root) {
	if(root == NULL)
		return;
	cout << root -> data << ' ';
	preorder(root -> left);
	preorder(root -> right);
}

template<class T>
void BST::inorder(BSTNode *root) {
	if(root == NULL)
		return;
	inorder(root -> left);
	cout << root -> data << ' ';
	inorder(root -> right);
}

template<class T>
void BST::postorder(BSTNode *root) {
	if(root == NULL)
		return;
	postorder(root -> left);
	postorder(root -> right);
	cout << root -> data << ' ';
}

int main() {
	BST<int> bst = new BST<int>();
	bst.insert(1);
	bst.insert(2);
	bst.insert(0);

	cout << bst.contains(1) << ' ' << bst.contains(2) << ' ' << bst.contains(3) << endl;

	bst.printInorder();
	bst.printPreorder();
	bst.printPostorder();
	return 0;
}
