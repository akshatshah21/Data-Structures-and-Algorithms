#include<map>
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

void diag_sum_util(Node *root, int d, map<int, int> &diags) {
    if(!root)   return;
    diags[d] += root -> data;
    diag_sum_util(root -> right, d, diags);
    diag_sum_util(root -> left, d+1, diags);
}
vector <int> diagonalSum(Node* root) {
    map<int, int> diags; // <dist, diag sum>
    diag_sum_util(root, 0, diags);
    vector<int> sums;
    for(const auto &i: diags)
        sums.emplace_back(i.second);
    return sums;
}
