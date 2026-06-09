/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode *tail = &dummy;
    tail->next = NULL;

    while(list1 != NULL && list2 != NULL){

        struct ListNode *new = (struct ListNode *)malloc(sizeof(struct  ListNode));

        if(list1->val <= list2->val){
            new->val = list1->val;
            list1 = list1->next;
        }
        else{
            new->val = list2->val;
            list2 = list2->next;
        }
        new->next = NULL;
        tail->next = new;
        tail = new;
    }

    while(list1 != NULL){
        struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = list1->val;
        list1 = list1->next;
        new->next = NULL;
        tail->next = new;
        tail = new;
    }

    while(list2 != NULL){
        struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = list2->val;
        list2 = list2->next;
        new->next = NULL;
        tail->next = new;
        tail = new;
    }

    return dummy.next;
}