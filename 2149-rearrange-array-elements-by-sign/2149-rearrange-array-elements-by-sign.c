/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* pos = (int *)malloc(numsSize * sizeof(int));
    int* neg = (int *)malloc(numsSize * sizeof(int));
    int p = 0;
    int n = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > 0){
            pos[p++] = nums[i];
        }
        else{
            neg[n++] = nums[i];
        }
    }
    p = 0;
    n = 0;
    for(int i = 0; i < numsSize; i++){
        if(i % 2 == 0){
            nums[i] = pos[p++];
        }
        else{
            nums[i] = neg[n++];
        }
    }
    free(pos);
    free(neg);
    return nums;

}