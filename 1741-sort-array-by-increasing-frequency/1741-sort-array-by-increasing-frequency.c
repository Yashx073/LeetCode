/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b){
    return (*(int*)a - *(int *)b);
}

int pair(const void* a, const void* b){
    int* x = *(int **)a;
    int* y = *(int **)b;

    if(x[1] != y[1]){
        return x[1] - y[1];
    }
    return y[0] - x[0];
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    int** arr = (int **)malloc(numsSize * sizeof(int *));
    *returnSize = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    for(int i = 0; i < numsSize; i++){
        arr[i] = (int * )malloc(2 * sizeof(int));
    }

    for(int i = 0; i < numsSize; i++){
        int count = 1;

        while(i+1 < numsSize && nums[i] == nums[i+1]){
            count++;
            i++;
        }
        arr[*returnSize][0] = nums[i];
        arr[*returnSize][1] = count;
        (*returnSize)++;
    }
    qsort(arr, *returnSize, sizeof(int *), pair);
    int* result = (int *)malloc(numsSize * sizeof(int));
    int pos = 0;
    for(int i = 0; i < *returnSize; i++){
        for(int j = 0; j < arr[i][1]; j++){
            result[pos++] = arr[i][0];
        }
        free(arr[i]);
    }
    *returnSize = numsSize;
    free(arr);
    return result;
}