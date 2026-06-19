/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* concatWithReverse(int* nums, int numsSize, int* returnSize) {
    int *ans = (int *)malloc((2*numsSize) * sizeof(int));

    for(int i = 0; i < numsSize; i++){
        ans[i] = nums[i];
    }
    int n = numsSize -1;
    int k = 1;
    for(int j = n; j >= 0; j--){
        ans[n + k] = nums[j];
        k++; 
    }
    *returnSize = 2*numsSize;
    return ans;
}