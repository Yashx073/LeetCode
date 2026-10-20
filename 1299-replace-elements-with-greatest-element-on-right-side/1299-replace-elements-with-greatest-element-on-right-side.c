int* replaceElements(int* arr, int arrSize, int* returnSize) {

    int* max = (int *)malloc(arrSize * sizeof(int));
    int maxR = -1;

    for(int i = arrSize - 1; i >= 0; i--){
        int curr = arr[i];
        max[i] = maxR;

        if(curr > maxR){
            maxR = curr;
        }
    }

    *returnSize = arrSize;
    return max;
}