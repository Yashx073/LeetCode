/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rev(struct ListNode* head){
    struct ListNode* prev = NULL;
    struct ListNode* current = head;

    while(current != NULL){
        struct ListNode* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    fast = head;
    slow = rev(slow);

    while(slow != NULL){
        if(fast->val != slow->val){
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}