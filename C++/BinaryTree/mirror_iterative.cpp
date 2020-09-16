// LeetCode: https://leetcode.com/problems/invert-binary-tree/
// GFG Practice: https://practice.geeksforgeeks.org/problems/mirror-tree/1

#include <algorithm>
#include<queue>
using namespace std;
class Node {
public:
	int data;
	Node *left, *right;
	Node() {
		left = right = nullptr;
		data = 0;
	}
	Node(int data) {
		this -> data = data;
		left = right = nullptr;
	}
};

void mirror(Node *root) {
	if(root) {
		queue<Node*> q;
		q.push(root);
		Node *curr;
		while(!q.empty()) {
			curr = q.front();
			q.pop();
			if(curr -> left)
				q.push(curr -> left);
			if(curr -> right)
				q.push(curr -> right);
			swap(curr -> left, curr -> right);
		}
	}
}

