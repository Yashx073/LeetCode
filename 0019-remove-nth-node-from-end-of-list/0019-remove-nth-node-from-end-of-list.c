/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int count = 0;
    struct ListNode *  p = head;
    while(p != NULL){
        p = p->next;
        count++;
    }

    if(n == count){
        struct ListNode * temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    p = head;
    int i = 0;
    while(i  != count - n-1){
        p = p->next;
        i++;
    }
    struct ListNode  * q = p->next;
    p->next = q->next;
    free(q);
    return head;
}