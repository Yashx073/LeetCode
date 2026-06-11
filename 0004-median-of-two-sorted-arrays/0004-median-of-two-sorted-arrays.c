double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int sum[nums1Size + nums2Size];
    int j=0, k=0,l=0;
    while(j < nums1Size && k < nums2Size){
        if(nums1[j] <= nums2[k]){
            sum[l] = nums1[j];
            l++;
            j++;
        }
        else{
            sum[l] = nums2[k];
            l++;
            k++;
        }
    }

        
        while(j != nums1Size){
            sum[l] = nums1[j];
            l++;
            j++;
        }
        while(k != nums2Size){
            sum[l] = nums2[k];
            l++;
            k++;
        }

        if((nums1Size + nums2Size) % 2 == 1){
            int mid = ((nums1Size + nums2Size) / 2);
            return sum[mid]; 
        }
        else{
            int mid = (nums1Size + nums2Size)  / 2;
            int mid2 = mid -1;
            return ((sum[mid] + sum[mid2]) / 2.0);
        }
    }
