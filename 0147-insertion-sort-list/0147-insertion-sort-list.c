/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    
    struct ListNode dummy;
    dummy.next = NULL;

    while(head != NULL){
        struct ListNode* next = head->next;
        struct ListNode* p = &dummy;

        while(p->next != NULL && p->next->val < head->val){
            p = p->next;
        }

        head->next = p->next;
        p->next = head;

        head = next;
    }

    return dummy.next;
}