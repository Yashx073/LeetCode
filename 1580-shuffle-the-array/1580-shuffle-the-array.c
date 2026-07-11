

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int* result = (int*)malloc((2*n)*sizeof(int));
    *returnSize = 2*n;
    int x = 0;

    for(int i = 0; i < n; i++){
        result[x++] = nums[i];
        result[x++] = nums[n + i];
    }

    return result;
}