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

int count_leaves(Node *root) {
	if(!root)
		return 0;
	int l = count_leaves(root -> left);
	int r = count_leaves(root -> right);
	if(!l && !r)
		return 1;
	else
		return l+r;
}
