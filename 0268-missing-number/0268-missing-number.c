int missingNumber(int* nums, int numsSize) {
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
    }
    int sum0 = 0;
    for(int i = 0; i <= numsSize; i++){
        sum0 += i;
    }

    return (sum0-sum);
}