

class Node {
public:
	int val;
	Node *left, *right;

	Node() : val(0), left(nullptr), right(nullptr) {}
	Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
  if(root) {
    Node *curr = root, par;
    while(curr) {
      par = curr;
      if(key < curr -> val)
        curr = curr -> left;
      else if(key > curr -> val)
        curr = curr -> right;
      else
        break;
    }
    if(key < par -> val)
      par -> left = new Node(key);
    else if(key > par -> val)
      par -> right = new Node(key);
  }
  else
    root = new Node(key);
  return root;
}
