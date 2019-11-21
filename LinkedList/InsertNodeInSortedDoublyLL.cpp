/* Question link (HackerRank): https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    if(head == NULL) {
        head = new DoublyLinkedListNode(data);
        return head;
    }
    DoublyLinkedListNode *node = new DoublyLinkedListNode(data);
    
    if(data < head -> data) { // insert at head condition
        node -> next = head;
        head -> prev = node;
        head = node;
        return head;
    }
    DoublyLinkedListNode *trav;
    // insert somewhere in the middle condition
    for(trav = head; trav -> next != NULL && trav -> data < data; trav = trav -> next) {}
    if(trav -> data >= data) {
        node -> next = trav;
        node -> prev = trav -> prev;
        node -> prev -> next =  node;
        trav -> prev = node;
        return head;
    }
    // Last element reached, and new node needs to be inserted at tail
    trav -> next = node;
    node -> prev = trav;
    return head;
}