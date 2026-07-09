/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *p = head;
    if(!head || !head->next) return false;
    while(p->next){
        if(p->val == INT_MAX) return true;
        p->val = INT_MAX;
        p = p->next;
    }
    return false;
}