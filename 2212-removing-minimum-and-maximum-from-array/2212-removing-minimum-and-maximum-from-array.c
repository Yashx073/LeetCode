int minimumDeletions(int* nums, int numsSize) {
    int min = 0;
    int max = 0;

    for(int i = 1; i < numsSize; i++){
        if(nums[i] < nums[min]){
            min = i;
        }
    }

    for(int i = 1; i < numsSize; i++){
        if(nums[max] < nums[i]){
            max = i;
        }
    }
    
    if(min > max){
        int temp = min;
        min = max;
        max = temp;
    }

    int left = max + 1;
    int right = numsSize - min;
    int both = min + 1 + numsSize - max;

    int result = left;

    if(right < result){
        result = right;
    }

    if(both < result){
        result = both;
    }

    return result;
}