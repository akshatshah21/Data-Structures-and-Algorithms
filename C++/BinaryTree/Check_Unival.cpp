/**
 * https://leetcode.com/problems/univalued-binary-tree/submissions/
 *
 * A binary tree is univalued if every node in the tree has the same value.
 * Return true if and only if the given tree is univalued.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root) return false;
        return unival(root->left, root->val) && unival(root->right, root->val);
    }

    bool unival(TreeNode* root, int val) {
        if(!root) return true;
        return (root->val == val) && unival(root->left, val) && unival(root->right, val);
    }
};
