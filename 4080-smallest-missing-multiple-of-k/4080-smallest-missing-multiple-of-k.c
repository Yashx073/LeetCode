int compare(const void* a, const void* b){
    return (*(int *)a - *(int *)b);
}

int missingMultiple(int* nums, int numsSize, int k) {
    int count = 1;
    qsort(nums, numsSize, sizeof(int), compare);

    for(int i = 0; i < numsSize; i++){
        if(k*count == nums[i]){
            count++;
        }
    }
    return (k*count);
}