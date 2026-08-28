/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode beforedummy;
    struct ListNode afterdummy;

    struct ListNode* before = &beforedummy;
    struct ListNode* after = &afterdummy;

    struct ListNode* current = head;

    while(current != NULL){
        if(current->val < x){
            before->next = current;
            before = before->next;
        }
        else{
            after->next = current;
            after = after->next;
        }
        current = current->next;
    }

    after->next = NULL;
    before->next = afterdummy.next;

    return beforedummy.next;
}