/* Question link (HackerRank): https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem */
bool has_cycle(SinglyLinkedListNode* head) {
    if(head == NULL)    return false;
    if(head -> next == NULL)    return false;
    for(SinglyLinkedListNode *slow = head -> next, *fast = head -> next -> next;
    slow != NULL && fast != NULL && fast -> next != NULL;
    slow = slow -> next, fast = fast -> next -> next) {
        if(slow == fast)    return true;
    }
    return false;
}