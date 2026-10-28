int rev(int n){
    int temp = 0;
    while(n != 0){
        int t = n % 10;
        temp = temp * 10 + t;
        n /= 10;
    }
    return temp;
}

int compare(const void* a, const void* b){
    return (*(int *)a - *(int *)b);
}

int countDistinctIntegers(int* nums, int numsSize) {

    int* arr = (int *)malloc((2 * numsSize) * sizeof(int));
    int count = 1;

    for(int i = 0; i < 2*numsSize; i++){
        if(i < numsSize){
            arr[i] = nums[i];
        }
        else{
            arr[i] = rev(nums[i-numsSize]);
        }
    }

    qsort(arr, 2*numsSize, sizeof(int), compare);
    for(int i = 1; i < (2*numsSize); i++){
        if(arr[i] != arr[i-1]){
            count++;
        }
    }
    return count;
}