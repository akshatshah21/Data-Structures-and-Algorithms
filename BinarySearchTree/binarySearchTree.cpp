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

	BSTNode<T> *root;
	BSTNode<T>* insert(BSTNode<T>* root, T x);
	void preorder(BSTNode<T> *root);
	void inorder(BSTNode<T> *root);
	void postorder(BSTNode<T> *root);
	BSTNode<T>* removeNode(BSTNode<T> *root, T key);
	BSTNode<T>* findMinNode(BSTNode<T>* root);
	BSTNode<T>* findMaxNode(BSTNode<T>* root);
	void copyNodeData(BSTNode<T>* from, BSTNode<T>* to);
	int size(BSTNode<T>* root);
public:

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
	T min();
	T max();
	bool find(T key);
	int size();
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
		root = new BSTNode<T>(x);

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
void BST<T>::copyNodeData(BSTNode<T>* from, BSTNode<T>* to) {
	to -> data = from -> data;
}

template<class T>
void BST<T>::remove(T key) {
	root = removeNode(root, key);
}

template<class T>
BST<T>::BSTNode<T>* BST<T>::removeNode(BSTNode<T>* root, T key) {
	if(root == NULL) // not found
		return NULL;
	if(key < root -> data)
		root -> left = removeNode(root -> left, key);
	else if(key > root -> data)
		root -> right = removeNode(root -> right, key);
	else {
		// Node found
		// Case 1: No children
		if(root -> right == NULL && root -> left == NULL) {
			delete root;
			root = NULL;
		}
		// Case 2: One child
		else if(root -> right == NULL) {
			BSTNode<T>* temp = root;
			root = root -> left;
			delete temp;
		}
		else if(root -> left == NULL) {
			BSTNode<T>* temp = root;
			root = root -> right;
			delete temp;
		}
		//Case 3: Two children
		else {
			BSTNode<T>* successor = findMinNode(root->right);
			copyNodeData(successor, root);
			root -> right = removeNode(root->right, successor->data);
		}

	}
	return root;
}

template<class T>
T BST<T>::min() {
	if(root == NULL) {
		cout << "BST empty\n";
		return 0;
	}
	BSTNode<T>* minNode = findMinNode(root);
	return minNode -> data;
}

template<class T>
BST<T>::BSTNode<T>* BST<T>::findMinNode(BSTNode<T>* root) {
	if(root == NULL)	return NULL;
	if(root -> left == NULL)	return root;
	return findMinNode(root->left);
}

template<class T>
T BST<T>::max() {
	if(root == NULL) {
		cout << "BST empty\n";
		return 0;
	}
	BSTNode<T>* maxNode = findMaxNode(root);
	return maxNode -> data;
}

template<class T>
BST<T>::BSTNode<T>* BST<T>::findMaxNode(BSTNode<T>* root) {
	if(root == NULL)	return NULL;
	if(root -> right == NULL)	return root;
	return findMaxNode(root -> right);
}

template<class T>
int BST<T>::size() {
	return size(root);
}

template<class T>
int BST<T>::size(BSTNode<T>* root) {
	if(root == NULL)
		return 0;
	return size(root -> left) + size(root -> right) + 1;
}


int main() {
	BST<int> bst = BST<int>();
	// Just some driver code for testing
	int x;
	int t;
	cin >> t;
	cout << "Enter numbers to add to BST set\n";
	while(t--) {
		cin >> x;
		bst.insert(x);
	}
	cout << "Size of BST: " << bst.size() << endl;
	bst.printInorder();
	bst.printPreorder();
	bst.printPostorder();
	bst.printLevelorder();
	cout << "Min element:" << bst.min() << endl;
	cout << "Max element:" << bst.max() << endl;

	int d;
	cout << "Enter element to remove:\n";
	cin >> d;
	bst.remove(d);
	bst.printLevelorder();
	cout << (bst.contains(50) ? "YES!\n" : "No...\n");
	return 0;
}
