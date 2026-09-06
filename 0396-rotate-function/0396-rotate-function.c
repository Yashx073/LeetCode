int maxRotateFunction(int* nums, int numsSize) {

    if(numsSize <= 1)
        return 0;

    long long sum = 0;
    long long current = 0;

    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
        current += (long long)i * nums[i];
    }

    long long max = current;

    for(int i = numsSize - 1; i > 0; i--){

        current += sum - (long long)numsSize * nums[i];

        if(current > max)
            max = current;
    }

    return (int)max;
}