long long gcd(long long a, long long b){
    while(b != 0){
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long maxPairStrength(int* nums, int numsSize) {
    long long max = 0;

    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){

            long long g = gcd(nums[i], nums[j]);

            long long num = (1LL * nums[i] * nums[j]) / (g * g);

            if(num > max){
                max = num;
            }
        }
    }

    return max;
}