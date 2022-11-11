/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode *pCurrent = head, *pSorted = NULL;

    while ( pCurrent != NULL ) {
        struct ListNode *pNext = pCurrent -> next;

        if ( pSorted == NULL || pSorted -> val >= pCurrent -> val ) {
            pCurrent -> next = pSorted;
            pSorted = pCurrent;

        } else {
            struct ListNode *pAux = pSorted;

            while ( pAux -> next != NULL && pAux -> next -> val < pCurrent -> val ) {
                pAux = pAux -> next;
            }

            pCurrent -> next = pAux -> next;
            pAux -> next = pCurrent;

        }

        pCurrent = pNext;
        
    }

    head = pSorted;

    return head;
    
}
