/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultArray(int* nums, int numsSize, int* returnSize) {
    int* arr1 = (int *)malloc(numsSize * (sizeof(int)));
    int* arr2 = (int *)malloc(numsSize * (sizeof(int)));
    int n1 = 0;
    int n2 = 0;
    arr1[n1] = nums[0];
    arr2[n2] = nums[1];
    for(int i = 2; i < numsSize; i++){
        if(arr1[n1] > arr2[n2]){
            arr1[++n1] = nums[i];
        }
        else{
            arr2[++n2] = nums[i];
        }
    }
    
    for(int i = 0; i <= n2; i++){
        arr1[n1+i+1] = arr2[i];
    }
    *returnSize = numsSize;
    free(arr2);
    return arr1;
}