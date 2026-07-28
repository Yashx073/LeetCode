/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b){
    return (*(int *)a - *(int *)b);
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int *result = (int *)malloc(arr1Size * sizeof(int));
    int k = 0;
    int count = 0;

    for(int i = 0; i < arr2Size; i++){
        for(int j = 0; j < arr1Size; j++){
            if(arr2[i] == arr1[j]){
                result[k++] = arr2[i];
                arr1[j] = INT_MAX;
                count++;
            }
        }
    }

    qsort(arr1, arr1Size, sizeof(int), compare);

    for(int i = 0; i < arr1Size-count; i++){
        result[k++] = arr1[i];
    }
    *returnSize = arr1Size;
    return result;
}