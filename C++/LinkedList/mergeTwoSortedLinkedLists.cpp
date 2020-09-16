/* Question link (HackerRank): https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem */


SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(head1 == nullptr)   return head2;
    if(head2 == nullptr)   return head1;
    SinglyLinkedListNode *head, *trav, *trav1 = head1, *trav2 = head2;
    if(head1 -> data < head2 -> data) {
        head = new SinglyLinkedListNode(head1 -> data);
        trav1 = trav1 -> next;        
    }
    else {
        head = new SinglyLinkedListNode(head2 -> data);
        trav2 = trav2 -> next;
    }
    trav = head;
    while(trav1 != nullptr && trav2 != nullptr) {
        while(trav1 != nullptr && trav1 -> data < trav2 -> data) {
            trav -> next = new SinglyLinkedListNode(trav1 -> data);
            trav1 = trav1 -> next;
            trav = trav -> next;
        }
        if(trav1 == nullptr)    break;
        while(trav2 != nullptr && trav1 -> data >= trav2 -> data) {
            trav -> next = new SinglyLinkedListNode(trav2 -> data);
            trav2 = trav2 -> next;
            trav = trav -> next;
        }
        if(trav2 == nullptr)	break;
    }
    while(trav1 != nullptr) {
        trav -> next = new SinglyLinkedListNode(trav1 -> data);
        trav1 = trav1 -> next;
        trav = trav -> next;
    }
    while(trav2 != nullptr) {
        trav -> next = new SinglyLinkedListNode(trav2 -> data);
        trav2 = trav2 -> next;
        trav = trav -> next;
    }
    trav -> next = nullptr;
    return head;
}