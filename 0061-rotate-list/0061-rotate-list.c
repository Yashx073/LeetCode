/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {

    if(head == NULL || head->next == NULL || k == 0){
        return head;
    }

    struct ListNode* temp = head;
    int count = 0;

    while(temp != NULL){
        temp = temp->next;
        count++;
    }

    k = k % count;

    if(k == 0){
        return head;
    }

    temp = head;

    for(int i = 0; i < count - k - 1; i++){
        temp = temp->next;
    }

    struct ListNode* start = temp->next;
    struct ListNode* result = start;
    temp->next = NULL;
    struct ListNode* tail = start;
    
    while(tail->next != NULL){
        tail = tail->next;
    }

    tail->next = head;
    return start;
}