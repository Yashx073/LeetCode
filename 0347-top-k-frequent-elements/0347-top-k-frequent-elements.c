/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b){
    return (*(int *)a - *(int *)b);
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = k;
    int **rep = (int **)malloc(numsSize * sizeof(int *));
    int *arr = (int *)malloc(k * sizeof(int));
    int count = 0;
    int j = 0;
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize; i++) {
        rep[i] = (int *)malloc(2 * sizeof(int));
    }

    for(int i = 0; i < numsSize; i++){
        count = 0;
        while(i+1 < numsSize && nums[i] == nums[i+1]){
            count++;
            i++;
        }
        rep[j][0] = nums[i];
        rep[j][1] = count+1;
        j++;
    }
    
    for(int i = 0; i < j - 1; i++){
        for(int p = 0; p < j - 1; p++){
            if(rep[p][1] < rep[p+1][1]){
                int *temp = rep[p];
                rep[p] = rep[p+1];
                rep[p+1] = temp;
            }
        }
    }

    for(int i = 0; i < k; i++){
        arr[i] = rep[i][0];
    }

    return arr;
}