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

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    if(!root)
        return;
    if(root -> key == key) {
        findPreSuc(root -> left, pre, suc, key);
        findPreSuc(root -> right, pre, suc, key);
        return;
    }
    if(root -> key > key) {
        suc = root;
        findPreSuc(root -> left, pre, suc, key);
    }
    else if(root -> key < key) {
        pre = root;
        findPreSuc(root -> right, pre, suc, key);
    }
}


// Alternatively, we can also handle the case of root -> key == key as below:
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key) {
	if(!root)
		return;
	if(root -> key == key) {
		if(root -> left) {
			// pre = rightmost child in left subtree
			pre = root -> left;
			while(pre -> right)
				pre = pre -> right;
		}   // else, don't change pre
		if(root -> right) {
			// suc = leftmost child in right subtree
			suc = root -> right;
			while(suc -> left)
				suc = suc -> left;
		}   // else, don't change suc
	}
	else if(root -> key < data) {
		pre = root;
		findPreSuc(root -> right, pre, suc, key);
	}
	else {
		suc = root;
		findPreSuc(root -> left, pre, suc, key);
	}
}
