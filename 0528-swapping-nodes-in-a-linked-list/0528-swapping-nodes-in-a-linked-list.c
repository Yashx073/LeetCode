/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k) {
   struct ListNode* p = head;
   struct ListNode* q = head;
    int n = 0;
   while(p != NULL){
    p = p->next;
    n++;
   }
    p = head;

   for(int i = 1; i < k; i++){
    p = p->next;
   } 

   for(int i = 1; i < n - k +1; i++){
     q = q->next;
   }

    int temp = p->val;
    p->val = q->val;
    q->val = temp;

    return head;
}