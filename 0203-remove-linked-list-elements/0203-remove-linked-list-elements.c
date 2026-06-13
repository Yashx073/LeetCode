/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {

    while(head != NULL && head->val == val){
        head = head->next;
    }

    struct ListNode *p = head;

    while(p != NULL && p->next != NULL){
        if(p->next->val == val){
            p->next = p->next->next;
        }
        else {
            p = p->next;
        }
    }
    return head;
}