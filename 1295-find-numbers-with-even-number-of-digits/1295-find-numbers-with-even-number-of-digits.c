int cot(int n){
    int count = 0;
    while(n > 0){
        count++;
        n /= 10;
    }
    return count;
}

int findNumbers(int* nums, int numsSize) {
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        if(cot(nums[i]) % 2 == 0){
            count++;
        }
    }
    return count;
}