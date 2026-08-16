/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b){
    return (*(int *)a - *(int *)b);
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    for(int i = 0; i < numsSize; i++){
        nums[i] = pow(nums[i], 2);
    }
    qsort(nums, numsSize, sizeof(int), compare);
    *returnSize = numsSize;
    return nums;
}