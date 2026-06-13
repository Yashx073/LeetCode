int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* count = (int *)malloc(2 * sizeof(int));
    count[0] = -1;
    count[1] = -1;

    int i = 0;

    while(i < numsSize && nums[i] != target){
        i++;
    }

    if (i == numsSize) {
        return count;
    }

    count[0] = i;

    while(i < numsSize && nums[i] == target){
        i++;
    }

    count[1] = i - 1;

    return count;
}