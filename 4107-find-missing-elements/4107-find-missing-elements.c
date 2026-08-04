/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void*a, const void*b){
    return (*(int *)a - *(int *)b);
}

int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    int count = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    int *arr = (int *)malloc((nums[numsSize-1]-nums[0]) * sizeof(int));
    int i = 0;
    int low = nums[0];
    int high = nums[numsSize-1];
    while(i < numsSize){
        if(nums[i] == low){
            i++;
        }
        else{
            arr[count++] = low;
        }
        low++;
    }
    *returnSize = count;
    return arr;
}