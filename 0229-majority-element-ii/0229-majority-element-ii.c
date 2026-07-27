/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b){
    return (*(int *)a - *(int *)b);
}

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int **matrix = (int **)malloc(numsSize * sizeof(int *));
    int j = 0;
    int n = 0;

    for(int i = 0; i < numsSize; i++){
        matrix[i] = malloc(2* sizeof(int));
    }

    qsort(nums, numsSize, sizeof(int), compare);

    for(int i = 0; i < numsSize; i++){
        int count = 0;
        while(i+1 < numsSize && nums[i] == nums[i+1]){
            count++;
            i++;
        }
        matrix[j][0] = nums[i];
        matrix[j][1] = count+1;
        j++;
    }
    int size = (numsSize/3);
    for(int i = 0; i < j; i++){
        if(matrix[i][1] > size){
            nums[n++] = matrix[i][0];
        }
    }
    *returnSize = n;
    return nums;
}