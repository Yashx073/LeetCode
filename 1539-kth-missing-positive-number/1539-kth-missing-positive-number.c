int findKthPositive(int* arr, int arrSize, int k) {
    int miss = 0;
    int num = 1;
    int i = 0;

    while(miss < k){
        if(i < arrSize && arr[i] == num){
            i++;
        }
        else{
            miss++;
        }
        num++;
    }
    return num-1;
}