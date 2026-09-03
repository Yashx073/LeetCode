bool uniformArray(int* nums1, int nums1Size) {
    bool Odd = true;
    bool Even = true;

    int minEven = INT_MAX;
    int minOdd = INT_MAX;

    for(int i = 0; i < nums1Size; i++){
        if(nums1[i] % 2 == 0){
            Odd = false;
            if(nums1[i] < minEven){
                minEven = nums1[i];
            }
        }
        else{
            Even = false;
            if(nums1[i] < minOdd){
                minOdd = nums1[i];
            }
        }
    }
    return Odd || Even || minEven > minOdd;
}