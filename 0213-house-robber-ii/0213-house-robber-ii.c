int robRange(int* nums, int start, int end) {
    
    int p1 = 0;
    int p2 = 0;

    for(int i = start; i <= end; i++){
        int current = p1;

        if(p2 + nums[i] > current){
            current = p2 + nums[i];
        }

        p2 = p1;
        p1 = current;
    }
    return p1;
}

int rob(int* nums, int numsSize){
    if(numsSize == 0){
        return 0;
    }

    if(numsSize == 1){
        return nums[0];
    }

    int case1 = robRange(nums, 0, numsSize-2);
    int case2 = robRange(nums, 1, numsSize-1);

    return (case1 > case2) ? case1 : case2;
}