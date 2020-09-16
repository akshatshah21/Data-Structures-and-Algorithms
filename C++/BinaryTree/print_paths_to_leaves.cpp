#include<iostream>
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

void print_paths_util(Node *root, vector<int> &path) {
	if(root) {
		path.emplace_back(root -> data);
		if(!root -> left && !root -> right) {
			for(const int &i: path)
				cout << i << ' ';
			cout << '\n';
		} else {
			print_paths_util(root -> left, path);
			print_paths_util(root -> right, path);
		}
		path.pop_back();
	}
}

void print_paths(Node *root) {
	if(root) {
		vector<int> path;
		print_paths_util(root, path);
	}
}
