int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int minimumOperations(int* nums, int numsSize) {
    int count = 0;
    if(numsSize == 0 || nums == NULL){
        return 0;
    }
    while(1){
        
        qsort(nums, numsSize, sizeof(int), compare);
        if(nums[numsSize-1] == 0)
            break;
        
        int j = 0;
        while(nums[j] == 0){
            j++;
        }
        int x = nums[j];
        for(int i = 0; i < numsSize; i++){
            if(nums[i] > 0){
                nums[i] -= x;
            }    
        }
        count++;
    }
    return count;
}