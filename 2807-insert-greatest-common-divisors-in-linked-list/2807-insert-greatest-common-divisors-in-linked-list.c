/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    struct ListNode* temp = head;

    while(temp->next != NULL){
        int a = temp->val;
        int b = temp->next->val;
        int g = gcd(a, b);

        struct ListNode* aN = (struct ListNode*)malloc(sizeof(struct ListNode));
        aN->val = g;
        aN->next = temp->next;
        temp->next = aN;

        temp = temp->next->next;
    }

    return head;
}