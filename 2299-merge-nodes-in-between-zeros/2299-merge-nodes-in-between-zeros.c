/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* nw = &dummy;
    struct ListNode* temp = head;

    while(temp != NULL){
        if(temp->next != NULL && temp->val == 0){
            int sum = 0;
            temp = temp->next;
            while(temp != NULL && temp->val != 0){
                sum += temp->val;
                temp = temp->next;
            }
            struct ListNode* new = malloc(sizeof(struct ListNode));
            nw->next = new;
            new->val = sum;
            new->next = NULL;
            nw = nw->next;
        }
        else{
            temp = temp->next;
        }
    }
    return dummy.next;
}