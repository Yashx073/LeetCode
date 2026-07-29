int compare(const void* a, const void* b){
    return (*(int *)a - *(int *)b);
}

int compareFreq(const void *a, const void *b){
    int *x = *(int **)a;
    int *y = *(int **)b;
    return x[1] - y[1];
}

int findLeastNumOfUniqueInts(int* arr, int arrSize, int k){
    qsort(arr, arrSize, sizeof(int), compare);
    int **result = (int **)malloc(arrSize * sizeof(int *));
    for(int i = 0; i < arrSize; i++){
        result[i] = malloc(2 * sizeof(int));
    }
    int p = 0;
    int count = 1;
    for(int i = 0; i < arrSize; i++){
        count = 1;
        while(i+1 < arrSize && arr[i] == arr[i+1]){
            count++;
            i++;
        }
        result[p][0] = arr[i];
        result[p][1] = count;
        p++;
    }

    qsort(result, p, sizeof(int *), compareFreq);

    for(int i = 0; i < p; i++){
        if(k >= result[i][1]){
            k -= result[i][1];
            result[i][1] = 0;
        }
        else{
            break;
        }
    }

    count = 0;
    for(int i = 0; i < p; i++){
        if(result[i][1] > 0){
            count++;
        }
    }
    return count;
}