/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {

    int* arr = (int *)calloc((numsSize+1), sizeof(int));
    int* result = (int *)malloc(numsSize * sizeof(int));

    for(int i = 0; i < numsSize; i++){
        arr[nums[i]]++;
    }

    *returnSize = 0;

    for(int i = 1; i < numsSize+1; i++){
        if(arr[i] == 2){
            result[(*returnSize)++] = i;
        }
    }

    return result;
}