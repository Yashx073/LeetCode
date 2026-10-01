int deleteAndEarn(int* nums, int numsSize) {

    int total[10001] = {0};

    for(int i = 0; i < numsSize; i++) {
        total[nums[i]] += nums[i];
    }

    int prev = 0;
    int curr = 0;

    for(int i = 1; i <= 10000; i++) {

        int next;

        if(prev + total[i] > curr)
            next = prev + total[i];
        else
            next = curr;

        prev = curr;
        curr = next;
    }

    return curr;
}