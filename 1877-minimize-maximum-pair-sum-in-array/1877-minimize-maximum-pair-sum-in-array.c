int minPairSum(int* nums, int numsSize){
    int min = INT_MAX;
    int max = INT_MIN;
    int* freq = (int *)calloc(100001, sizeof(int));
    
    for(int i = 0; i < numsSize; i++){
        if(min > nums[i]){
            min = nums[i];
        }
        if(max < nums[i]){
            max = nums[i];
        }
        freq[nums[i]]++;
    }

    int max_sum = 0;
    int l = min;
    int r = max;

    while( l <= r){
        if(freq[l] == 0){
            l++;
        }
        else if(freq[r] == 0){
            r--;
        }
        else{
            max_sum = fmax(max_sum, l+r);
            freq[l]--;
            freq[r]--;
        }
    }
    return max_sum;
}