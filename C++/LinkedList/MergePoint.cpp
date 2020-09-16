/* Question link (HackerRank): https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *trav1 = head1, *trav2 = head2;
    set<SinglyLinkedListNode*> l1;
    while(trav1 != NULL) {
        if(l1.find(trav1) == l1.end()) {
            l1.insert(trav1);
        }
        trav1 = trav1 -> next; 
    }
    while(trav2 != NULL) {
        if(l1.find(trav2) != l1.end())   return trav2 -> data;
    }
    return -1;
}

/* Aliter 
	Based on https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/editorial*/
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *trav1 = head1, *trav2 = head2;
    int len1 = 0, len2 = 0;
    for(trav1 = head1; trav1 != NULL; trav1 = trav1 -> next)
        len1++;
    for(trav2 = head2; trav2 != NULL; trav2 = trav2 -> next)
        len2++;
    if(len1 < len2) {
        SinglyLinkedListNode *temp = head2;
        head2 = head1;
        head1 = temp;
        int templ = len1;
        len1 = len2;
        len2 = templ;
    }
    // Now len1 is >= len2, l1 is larger list
    trav1 = head1, trav2 = head2;
    for(int i=0;i<len1-len2;i++)
        trav1 = trav1 -> next;
    while(trav1 != NULL && trav2 != NULL && trav1 != trav2) {
        trav1 = trav1 -> next;
        trav2 = trav2 -> next;
    }
    if(trav1 != NULL && trav2 != NULL)  return trav1 -> data;
    return -999;

}