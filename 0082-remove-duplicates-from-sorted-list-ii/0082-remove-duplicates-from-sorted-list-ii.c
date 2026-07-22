/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL){
        return NULL;
    }
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* q = &dummy;
    struct ListNode* p = head;
    int duplicate = 0;

    while(p != NULL){
        if(p->next != NULL && p->val == p->next->val){
            duplicate = p->val;
            while(p != NULL && p->val == duplicate){
                p = p->next;
            }
            q->next = p;
        }
        else{
            q = p;
            p = p->next;
        }
    }
    return dummy.next;
}