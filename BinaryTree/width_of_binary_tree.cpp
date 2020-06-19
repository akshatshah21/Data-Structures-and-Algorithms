#include<algorithm>
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

/* x = current x coordinate
 * maxl = maximum negative x
 * maxr = maximum x
 */
void width_util(Node *root, int x, int &maxl, int &maxr) {
	if(!root)
		return;
	if(x >= 0)
		maxr = max(maxr, x);
	else
		maxl = min(maxl, x);
	width_util(root -> left, x-1, maxl, maxr);
	width_util(root -> right, x+1, maxl, maxr);
}

int width(Node *root) {
	if(!root)
		return 0;
	int maxl = 0, maxr = 0;
	width_util(root, 0, maxl, maxr);
	return maxr - maxl + 1;
}
