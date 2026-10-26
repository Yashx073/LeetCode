/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rev(struct ListNode* head){
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int pairSum(struct ListNode* head) {
    struct ListNode* temp = head;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = rev(slow);

    int max = 0;

    while(slow != NULL){
        int sum = head->val + slow->val;
        max = (max > sum) ? max : sum;
        head= head->next;
        slow = slow->next;
    }

    return max;
}