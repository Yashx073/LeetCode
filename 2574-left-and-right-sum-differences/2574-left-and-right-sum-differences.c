/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    int* left = (int *)malloc(numsSize * sizeof(int));
    int* right = (int *)malloc(numsSize * sizeof(int));
    left[0] = 0;
    right[numsSize - 1] = 0;
    for(int i = 1; i < numsSize; i++){
        left[i] = left[i-1] + nums[i-1];
    }
    for(int i = numsSize-2; i >= 0; i--){
        right[i] = right[i+1] + nums[i+1];
    }
    for(int i = 0; i < numsSize; i++){
        nums[i] = abs(left[i] - right[i]);
    }
    free(left);
    free(right);
    *returnSize = numsSize;
    return nums;
}