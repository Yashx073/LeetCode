int pivotIndex(int* nums, int numsSize) {
    int leftSum = 0;
    int rightSum = 0;

    for(int i = 0; i < numsSize; i++){
        rightSum += nums[i];
    }

    for(int i = 0; i < numsSize; i++){
        if(leftSum == rightSum - leftSum - nums[i]){
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}