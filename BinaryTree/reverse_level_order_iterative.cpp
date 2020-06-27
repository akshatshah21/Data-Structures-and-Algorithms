#include<iostream>
#include<queue>
#include<vector>
using namespace std;

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

void print_reverse_level_order(Node *root) {
	if(root) {
		queue<Node*> q;
		vector<vector<int>> v;
		Node *curr;
		q.push(root);
		int levels = 0;
		int next_level=1, this_level;
		while(!q.empty()) {
			this_level = next_level;
			next_level = 0;
			vector<int> temp;
			while(this_level--) {
				curr = q.front();
				q.pop();
				temp.emplace_back(curr -> data);
				if(curr -> left) {
					q.push(curr -> left);
					next_level++;
				}
				if(curr -> right) {
					q.push(curr -> right);
					next_level++;
				}
			}
			v.push_back(temp);
			levels++;
		}
		for(int i=levels-1;i>=0;i--) {
			for(const int &j: v[i])
				cout << j << " ";
		}
	}
}

