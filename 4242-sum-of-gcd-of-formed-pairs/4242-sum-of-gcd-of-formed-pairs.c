int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int compare(const void* a, const void* b){
    return (*(int *)a - *(int *)b);
}

long long gcdSum(int* nums, int numsSize) {
    int *prefixGcd = (int *)malloc(numsSize * sizeof(int));
    long long sum = 0;
    int left = 0;
    int right = numsSize - 1;
    int mx = nums[0];
    for(int i = 0; i < numsSize; i++){
        if(mx < nums[i]){
            mx = nums[i];
        }
        prefixGcd[i] = gcd(nums[i], mx);
    }

    qsort(prefixGcd, numsSize, sizeof(int), compare);

    while(left < right){
        int temp = gcd(prefixGcd[left], prefixGcd[right]);
        sum += temp;
        left++;
        right--;
    }

    return sum;
}