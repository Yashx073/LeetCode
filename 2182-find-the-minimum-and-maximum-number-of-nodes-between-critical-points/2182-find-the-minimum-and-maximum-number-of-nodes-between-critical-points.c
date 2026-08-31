/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countNode(struct ListNode* head){
    struct ListNode* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    
    *returnSize = 2;
    int n = countNode(head);
    struct ListNode* temp = head;
    int* arr = (int *)malloc(n * sizeof(int));
    int* res = (int *)malloc(n * sizeof(int));

    if(n < 4){
        arr[0] = -1;
        arr[1] = -1;
        return arr;
    }

    for(int i = 0; i < n; i++){
        arr[i] = temp->val;
        temp = temp->next;
    }
    int r = -1;
    for(int i = 1; i < n-1; i++){
        if(arr[i] < arr[i-1] && arr[i] < arr[i+1]){
            res[++r] = i;
        }
        else if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            res[++r] = i;
        }
    }

    if(r < 1){
        res[0] = -1;
        res[1] = -1;
        return res;
    }

    int min = INT_MAX;
    int max = res[r] - res[0];

    for(int i = 1; i <= r; i++){
        if(res[i] - res[i-1] < min){
            min = res[i] - res[i-1];
        }
    }
    res[0] = min;
    res[1] = max;
    return res;
}