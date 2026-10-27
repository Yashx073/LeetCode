/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    
    struct ListNode* temp = list1;
    struct ListNode* end = list1;
    struct ListNode* l2 = list2;

    for(int i = 0; i < b+1; i++){
        end = end->next;
    }
    
    for(int i = 0; i < a-1; i++){
        temp = temp->next;
    }

    while(l2->next != NULL){
        l2 = l2->next;
    }

    temp->next = list2;
    l2->next = end;

    return list1;
}