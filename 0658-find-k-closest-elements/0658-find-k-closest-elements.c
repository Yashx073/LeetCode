int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    int a = 0;
    int b = arrSize - 1;

    while(b - a + 1 > k){
        if(abs(arr[a] - x) <= abs(arr[b] - x)){
            b--;
        }
        else{
            a++;
        }
    }
    *returnSize = k;
    return arr + a;
}