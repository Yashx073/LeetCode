/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b){
    return (*(int *)a - *(int *)b);
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int count = 0;
    int size = 0;
    int t = 0;
    if(nums1Size < nums2Size){
        
        size = nums2Size;
    }
    else{
        size = nums1Size;
    }
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);
    int *arr = malloc(size * sizeof(int));
    for(int i = 0; i < nums1Size; i++){
        for(int j = 0; j < nums2Size; j++){
            if(nums1[i] == nums2[j] && (count == 0 || nums1[i] != arr[count-1])){
                arr[count++] = nums1[i];
                break;
            }
        }
    }

    *returnSize = count ;
    return arr;
}