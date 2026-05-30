void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
   int i=0,j=0,k=0;
    int* nums = (int*)malloc((nums1Size + nums2Size) * sizeof(int));

    while(i < m && j < n){
        
        if (nums1[i] <= nums2[j]){
            nums[k]= nums1[i];
            i++;
            k++;
        }
        else{
            nums[k] = nums2[j];
            j++;
            k++;
       }
    }

    while(i < m){
        nums[k] = nums1[i];
        i++;
        k++;
    }

    while(j < n){
        nums[k] = nums2[j];
        j++;
        k++;
    }

    for(int x; x < m+n; x++){
        nums1[x]  = nums[x];
    }
    free(nums);
}