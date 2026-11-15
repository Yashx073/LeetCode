int numOfSubarrays(int* arr, int arrSize) {

    long long sum = 0;
    long long count = 0;

    for(int i = 0; i < arrSize; i++){
        sum += arr[i];
        count += sum % 2;
    }

    count += (arrSize - count) * count;

    return (int)(count % 1000000007);

}