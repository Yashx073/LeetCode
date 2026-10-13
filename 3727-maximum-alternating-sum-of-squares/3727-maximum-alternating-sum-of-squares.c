int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);  // ascending order
}

long long maxAlternatingSum(int* nums, int numsSize) {
    long long* arr = malloc(numsSize * sizeof(long long));

    for(int i = 0; i < numsSize; i++) {
        long long x = nums[i];
        arr[i] = (x < 0) ? -x : x;
    }

    qsort(arr, numsSize, sizeof(long long), compare);

    long long sum = 0;
    int len = numsSize / 2;

    for(int i = 0; i < numsSize; i++) {
        sum += (i < len ? -1LL : 1LL) * arr[i] * arr[i];
    }

    free(arr);
    return sum;
}