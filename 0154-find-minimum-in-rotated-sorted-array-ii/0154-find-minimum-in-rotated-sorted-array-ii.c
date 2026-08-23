int findMin(int* nums, int numsSize) {
    int min = INT_MAX;
    for(int i = 0; i < numsSize; i++){
        if(min > nums[i]){
            min = nums[i];
        }
    }
    return min;
}