int compare(const void* a, const void* b){
    return (*(int *)a - *(int *)b);
}

int smallestDistancePair(int* nums, int numsSize, int k) {
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    int left = 0;
    int right = nums[numsSize - 1] - nums[0];

    while(left < right){

        int mid = left + (right - left) / 2;

        int i = 0;
        int count = 0;  

        for(int j = 0; j < numsSize; j++){

            while(nums[j] -  nums[i] > mid){
                i++;
            }
        count += j - i;

        }

        if(count >= k){
            right = mid;
        }
        else{
            left = mid + 1;
        }

    }

    return left;

}