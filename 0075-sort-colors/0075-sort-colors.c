void sortColors(int* nums, int numsSize) {
    int* result = (int *)malloc(numsSize * sizeof(int));

    int i = 0;
    int x = 0;

    while(i < numsSize){
        if(nums[i] == 0){
            result[x++] = 0;
        }
        i++;
    }
    i = 0;
    while(i < numsSize){
        if(nums[i] == 1){
            result[x++] = 1;
        }
        i++;
    }
    i = 0;
    while(i < numsSize){
        if(nums[i] == 2){
            result[x++] = 2;
        }
        i++;
    }

    for(int j = 0; j < numsSize; j++){
        nums[j] = result[j];
    }

}