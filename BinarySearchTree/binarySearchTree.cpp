#include<iostream>
#include<queue>
using namespace std;
template<class T>
class BST {
private:
	template<class U>
	class BSTNode {
	public:
		U data;
		BSTNode *left, *right;

		BSTNode(U x, BSTNode *left=NULL, BSTNode *right=NULL) {
			this -> left = left;
			this -> right = right;
			this -> data = x;
		}
	};

	BSTNode<T>* insert(BSTNode<T>* root, T x);
	void preorder(BSTNode<T> *root);
	void inorder(BSTNode<T> *root);
	void postorder(BSTNode<T> *root);
	void removeNode(BSTNode<T> *root, T key);
public:
	BSTNode<T> *root; // shift this to private later

	BST() {
		root = NULL;
	}

	bool contains(T x);
	void insert(T x);
	void printPreorder();
	void printInorder();
	void printPostorder();
	void printLevelorder();
	void remove(T key);
};

template<class T>
bool BST<T>::contains(T x) {
	if(root == NULL)
		return false;
	BSTNode<T> *trav = root;
	while(trav != NULL) {
		if(x < trav -> data) {
			trav = trav -> left;
		}
		else if(x > trav -> data) {
			trav = trav -> right;
		}
		else	return true;
	}
	return false;
}

template<class T>
void BST<T>::insert(T x) {
	root = insert(root, x);
}

template<class T>
BST<T>::BSTNode<T>* BST<T>::insert(BSTNode<T>* root, T x) {
	if(root == NULL) {
		root = new BSTNode(x);

	}
	else if(x < root -> data) {
			root -> left = insert(root -> left, x);
	}
	else if(x > root -> data) {
		root -> right = insert(root -> right, x);
	}
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

template<class T>
void BST<T>::printLevelorder() {
	if(root == NULL) {
		cout << endl;
		return;
	}
	queue<BSTNode<T>*> q;
	q.push(root);
	while(!q.empty()) {
		BSTNode<T>* curr = q.front();
		q.pop();
		if(curr -> left != NULL)	q.push(curr -> left);
		if(curr -> right != NULL)	q.push(curr -> right);
		cout << curr -> data << ' ';
	}
	cout << endl;
}


template<class T>
void BST<T>::preorder(BSTNode<T> *root) {
	if(root == NULL)
		return;
	cout << root -> data << ' ';
	preorder(root -> left);
	preorder(root -> right);
}

template<class T>
void BST<T>::inorder(BSTNode<T> *root) {
	if(root == NULL)
		return;
	inorder(root -> left);
	cout << root -> data << ' ';
	inorder(root -> right);
}

template<class T>
void BST<T>::postorder(BSTNode<T> *root) {
	if(root == NULL)
		return;
	postorder(root -> left);
	postorder(root -> right);
	cout << root -> data << ' ';
}

template<class T>
void BST<T>::remove(T key) {
	removeNode(root, key);
}

template<class T>
BST<T>::BSTNode<T>* BST<T>::removeNode(BSTNode<T>* root, T key) {
	
}
int main() {
	BST<int> bst = BST<int>();
	int x;
	int t;
	cin >> t;
	cout << "Enter numbers to add to BST set\n";
	while(t--) {
		cin >> x;
		bst.insert(x);
	}
	bst.printInorder();
	bst.printPreorder();
	bst.printPostorder();
	bst.printLevelorder();
	return 0;
}
