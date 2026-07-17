/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int min(int* nums, int numsSize){
    int min = INT_MAX;
    int j = 0;
    for(int i = 0; i < numsSize; i++){
        if(min > nums[i]){
            min = nums[i];
            j = i;
        }
    }
    return j;
}

int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    for(int i = 0; i < k; i++){
        int p = min(nums, numsSize);
        nums[p] *= multiplier;
    }
    *returnSize = numsSize;
    return nums;
}