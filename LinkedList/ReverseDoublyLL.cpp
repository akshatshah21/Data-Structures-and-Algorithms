/* Question link (HackerRank): https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem */
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    if(head == NULL || head -> next == NULL)    return head;
    DoublyLinkedListNode *trav;
    for(trav = head; trav != NULL; trav = trav -> prev) {
        head = trav;
        DoublyLinkedListNode *temp = trav -> next;
        trav -> next = trav -> prev;
        trav -> prev = temp;
    }
    return head;
}