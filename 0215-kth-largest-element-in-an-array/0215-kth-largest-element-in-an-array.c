void heapify(int heap[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && heap[left] > heap[largest]){
        largest = left;
    }

    if(right < n && heap[right] > heap[largest]){
        largest = right;
    }

    if(largest != i){
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        heapify(heap, n, largest);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    for(int i = numsSize/2 -1; i >= 0; i--){
        heapify(nums, numsSize, i);
    }

    for(int i = numsSize - 1; i >= 0; i--){
        int temp = nums[0];
        nums[0] = nums[i];
        nums[i] = temp;
        heapify(nums, i, 0);
    }

    return nums[numsSize-k];
}