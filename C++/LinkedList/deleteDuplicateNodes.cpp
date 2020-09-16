/* Question link (HackerRank): https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem */

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    if(head == NULL)    return head;
    if(head -> next == NULL)    return head;
    for(SinglyLinkedListNode *trav = head; trav != NULL && trav -> next != NULL;) {
        if(trav -> data == trav -> next -> data) {
            // delete trav -> next, DON'T go ahead
            SinglyLinkedListNode *temp = trav -> next;
            trav -> next = trav -> next -> next;
            delete temp;
        }
        else {
            // just go ahead
            trav = trav -> next;
        }
    }
    return head;
}