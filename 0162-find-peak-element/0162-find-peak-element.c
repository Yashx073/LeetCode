int findPeakElement(int* nums, int numsSize) {
    int count = 0;
    for(int i = 1; i < numsSize; i++){
        if(nums[i-1] <  nums[i]){
            count = i;
        }
    }
    return count;
}