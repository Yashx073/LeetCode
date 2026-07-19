void heapify(int heap[], int n, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && heap[left] < heap[smallest]){
        smallest = left;
    }

    if(right < n && heap[right] < heap[smallest]){
        smallest = right;
    }

    if(smallest != i){
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        heapify(heap, n, smallest);
    }
}

int maximumProduct(int* nums, int numsSize, int k) {
    long long sum = 1;
    const int MOD = 1000000007;

    for(int i = numsSize/2 - 1; i >= 0; i--){
        heapify(nums, numsSize, i);
    }

    while(k--){
        nums[0]++;
        heapify(nums, numsSize, 0);
    }

    for(int i = 0; i < numsSize; i++){
        sum = (sum * nums[i]) % MOD;
    }

    return (int)sum;
}