int minimumSumSubarray(int* nums, int numsSize, int l, int r) {
    int min = INT_MAX;
    for(int i = l; i <= r; i++){
        int k = 0;
        
        for(int j = 0; j < i; j++){
            k += nums[j];
        }

        if(k > 0 && min > k){
            min = k;
        }

        for(int q = i; q < numsSize; q++){
            k = k + nums[q] - nums[q-i];

            if(k > 0 && k < min){
                min = k;
            }
        }
    }
    return min == INT_MAX ? -1 : min;
}