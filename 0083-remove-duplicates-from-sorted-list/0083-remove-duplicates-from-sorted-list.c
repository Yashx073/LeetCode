/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* p = head;
    struct ListNode* q = head;

    while(p != NULL){
        if(p->val == q->val){
            q->next = p->next;
        }
        else{
            q = q->next;
        }
        p = p->next;
    }
    return head;
}