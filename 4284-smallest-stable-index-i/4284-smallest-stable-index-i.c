int firstStableIndex(int* nums, int numsSize, int k) {
    int max = INT_MIN;

    int* arr = (int*)malloc(numsSize * sizeof(int));
    arr[numsSize - 1] = nums[numsSize - 1];

    for(int i = numsSize - 2; i >= 0; i--){
        if(nums[i] < arr[i + 1]){
            arr[i] = nums[i];
        }
        else{
            arr[i] = arr[i + 1];
        }
    }

    for(int i = 0; i < numsSize; i++){

        if(nums[i] > max){
            max = nums[i];
        }

        if(max - arr[i] <= k){
            free(arr);
            return i;
        }
    }

    free(arr);
    return -1;
}