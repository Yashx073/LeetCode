int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    return (x > y) - (x < y);
}

int minMoves(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int count = 0;

    for (int i = numsSize - 1; i > 0; i--) {
        count += nums[i] - nums[0];
    }

    return count;
}