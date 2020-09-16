/* Question link (HackerRank): https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem */
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    int len = 0;
    for(SinglyLinkedListNode *trav = head; trav != NULL; trav = trav -> next)
        len++;
    int pos = len - positionFromTail - 1;
    SinglyLinkedListNode *trav = head;
    for(int i=0; trav != NULL && i != pos; i++, trav = trav -> next){}
    return trav -> data;
}

/*********************************************************/

/* Recursive solution, because recursion is fundamental! */
int recur(SinglyLinkedListNode *head, int positionFromTail, bool *done) {
    
    if(head == NULL)    return 0;
    int n = recur(head -> next, positionFromTail, done);
    if(!(*done)) {
        if(n == positionFromTail) {
            *done = true;
            return head -> data;
        }
        return n+1;
    }
    return n;


}

int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    bool done = false;
    return recur(head, positionFromTail, &done);
}