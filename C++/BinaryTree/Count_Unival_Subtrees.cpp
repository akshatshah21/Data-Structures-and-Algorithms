/** A unival tree (which stands for "universal value") is a tree where
 * all nodes under it have the same value.
 * Given the root to a binary tree, count the number of unival subtrees.
*/

#include<utility>

pair<bool, int> count(Node *root, int val) {
	if(!root) return {true, 0};
	pair<bool, int> l = count(root->left, root->val);
	pair<bool, int> r = count(root->right, root->val);
	bool matches = root -> val == val;
	return {(matches && l.first && r.first), l.second + r.second + (l.first && r.first)};
}

int count_unival_subtrees(Node *root) {
	if(!root) return 0;
	pair<bool, int> l = count(root->left, root->val);
	pair<bool, int> r = count(root->right, root->val);
	return l.second + r.second + (l.first && r.first);
}
