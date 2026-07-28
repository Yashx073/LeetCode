int compare(const void* a, const void*b){
    return (*(int *)b - *(int *)a);
}

int findLucky(int* arr, int arrSize) {
    int count = 1;
    int k = 0;

    int *result = (int *)malloc(arrSize * sizeof(int));
    result[0] = -1;
    qsort(arr, arrSize, sizeof(int), compare);
    for(int i = 0; i < arrSize; i++){
        count = 1;
        while(i+1 < arrSize && arr[i] == arr[i+1]){
            count++;
            i++;
        }
        if(count == arr[i]){
            result[k++] = arr[i];
        }
    }   

    qsort(result, k, sizeof(int), compare);

    return result[0];
}