#include<queue>
#include<climits>
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

int maxLevelSum(Node* root) {
    if(!root)   return 0;
    int max_sum = INT_MIN;
    queue<Node*> q;
    q.push(root);
    Node *curr;
    int next_level = 1, this_level, sum;
    while(!q.empty()) {
        this_level = next_level;
        next_level = 0;
        sum = 0;
        for(int i=0;i<this_level;i++) {
            curr = q.front();
            q.pop();
            sum += curr -> data;
            if(curr -> left) {
                q.push(curr -> left);
                next_level++;
            }
            if(curr -> right) {
                q.push(curr -> right);
                next_level++;
            }
        }
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}
