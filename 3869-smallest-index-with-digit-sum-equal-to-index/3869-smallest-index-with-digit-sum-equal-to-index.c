int sum(int n){
    int sum = 0;
    while(n != 0){
        int temp = n % 10;
        sum +=  temp;
        n /= 10;
    }
    return sum;
}

int smallestIndex(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++){
        if(sum(nums[i]) == i){
            return i;
        }
    }
    return -1;
}