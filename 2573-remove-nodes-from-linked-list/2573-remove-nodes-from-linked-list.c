/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;

    while(current != NULL) {
        struct ListNode* nextNode = current->next;

        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

struct ListNode* removeNodes(struct ListNode* head) {

    head = reverse(head);

    struct ListNode* current = head;
    int maxVal = head->val;

    while(current != NULL && current->next != NULL) {

        if(current->next->val < maxVal) {
            struct ListNode* temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        else {
            current = current->next;

            if(current->val > maxVal) {
                maxVal = current->val;
            }
        }
    }

    head = reverse(head);

    return head;
}