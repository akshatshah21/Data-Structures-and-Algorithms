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

int count_internal_nodes(Node *root) {
	if(!root || !(root -> left || root -> right))
		return 0;
	return count_internal_nodes(root -> left) + count_internal_nodes(root -> right) + 1;
}
