// Question link: https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1



/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/
int getNthFromLast(Node *head, int n) {
    if(head == NULL)
        return -1;
    Node *f=head, *s=head;
    for(int i=0;i<n;i++) {
        if(f == NULL)
            return -1;
        f = f -> next;
    }
    while(f != NULL) {
        f = f-> next;
        s = s-> next;
    }
    return s -> data;
}
