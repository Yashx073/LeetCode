int compare(const void* a, const void* b){
    return (*(int *)b - *(int *)a);
}

int maxProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    return (nums[0]-1)*(nums[1]-1);
}