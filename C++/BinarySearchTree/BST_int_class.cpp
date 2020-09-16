#include <iostream>
#include<queue>
using namespace std;
class Node {
public:
	int val;
	Node *left, *right;

	Node() : val(0), left(nullptr), right(nullptr) {}
	Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

class BST {
	Node *root;

	Node* search(Node *root, int val);
	Node* insert_util(Node *root, int val);
	int find_min(Node* root);
	int find_max(Node* root);
	Node* remove_node(Node *root, int val);
	void inorder(Node *root);
	void preorder(Node *root);
	void postorder(Node *root);
	void level_order(Node *root);

public:
	BST() : root(nullptr) {}

	void insert(int val);
	void remove(int val);
	bool contains(int val);
	int min();
	int max();
	void print_inorder();
	void print_preorder();
	void print_postorder();
	void print_level_order();
};

/* Public method to insert a value in BSTNode
 * If value already present, makes no changes
 */
void BST:: insert(int val) {
	root = insert_util(root, val);
}

/* Private recursive method to insert a value in BST
 * If val is already present, it returns links upward unchanged
 * Else inserts a new node with value val as a leaf and returns links upwards
 */
Node* BST::insert_util(Node *root, int val) {
	if(root) {
		if(val < root -> val)
			root -> left = insert_util(root -> left, val);
		else if(val > root -> val)
			root -> right = insert_util(root -> right, val);
		else
			return root;
	}
	else
		root = new Node(val);
	return root;
}

/* Public method that returns true if param val is present in the BSTNode
 * Else returns false
 */
bool BST::contains(int val) {
	return search(root, val); // null is 0, non-null is non-zero
}

/* Searches for a value in subtree rooted at param root,
 * Returns pointer to the node if found
 * Else returns null
 */
Node* BST::search(Node *root, int val) {
	Node *res = nullptr;
	if(root) {
		if(val < root -> val)
			res = search(root -> left, val);
		else if(val > root -> val)
			res = search(root -> right, val);
		else
			res = root;
	}
	return res;
}

/* Public method for deletion of a value (if present) from the BSTNode
 */
void BST::remove(int val) {
	root = remove_node(root, val);
}

/* Private recursive method for deleting node with value value
 * Returns links upwards
 */
Node* BST::remove_node(Node *root, int val) {
	if(!root)
		return nullptr;
	if(val < root -> val)
		root -> left  = remove_node(root -> left, val);
	else if(val > root -> val)
		root -> right = remove_node(root -> right, val);
	else { // Node found
		// Case 1: No children
		if(!root -> left && !root -> right) {
			// Simply delete this node
			delete root;
			return nullptr;
		}
		// Case 2: One child
		else if(!root -> left) {
			Node* temp = root -> right;
			delete root;
			return temp;
		}
		else if(!root -> right) {
			Node *temp = root -> left;
			delete root;
			return temp;
		}
		// Case 3: Two children
		else {
			root -> val = find_min(root -> right); // inorder successor
			root -> right = remove_node(root -> right, root -> val);
		}
	}
	return root;
}

/* Public method to return minimum key in BST
 * Returns -1 if BST is empty
 */
int BST::min() {
	return find_min(root);
}

/* Private utility method to find minimum key in BSTNode
 * Returns -1 if BST is empty
 */
int BST::find_min(Node *root) {
	if(!root)
		return -1;
	while(root -> left)
		root = root -> left;
	return root -> val;
}

/* Public method to return maximum key in BST
* Returns -1 if BST is empty
 */
int BST::max() {
	return find_max(root);
}

/* Private utility method to find maximum key in BSTNode
 * Returns -1 if BST is empty
 */
int BST::find_max(Node *root) {
	if(!root)
		return -1;
	while(root -> right)
		root = root -> right;
	return root -> val;
}

/* Public methods to print different traversals of BST
 * Each method calls a private utility method
 */

void BST::print_inorder() {
	inorder(root);
	cout << "\n";
}

void BST::print_preorder() {
	preorder(root);
	cout << "\n";
}

void BST::print_postorder() {
	postorder(root);
	cout << "\n";
}

void BST::print_level_order() {
	level_order(root);
	cout << "\n";
}

/* Private methods for BST traversals
 */
void BST::inorder(Node *root) {
	if(root) {
		inorder(root -> left);
		cout << root -> val << " ";
		inorder(root -> right);
	}
}

void BST::preorder(Node *root) {
	if(root) {
		cout << root -> val << " ";
		preorder(root -> left);
		preorder(root -> right);
	}
}

void BST::postorder(Node *root) {
	if(root) {
		postorder(root -> left);
		postorder(root -> right);
		cout << root -> val << " ";
	}
}

void BST::level_order(Node *root) {
	if(root) {
		queue<Node*> q;
		q.push(root);
		Node *curr;
		while(!q.empty()) {
			curr = q.front();
			q.pop();
			cout << curr -> val << " ";
			if(curr -> left)
				q.push(curr -> left);
			if(curr -> right)
				q.push(curr -> right);
		}
	}
}

int main() {

	return 0;
}
