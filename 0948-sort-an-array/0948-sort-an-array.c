/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void heapDown(int heap[], int n, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && heap[left] > heap[smallest]){
        smallest = left;
    }

    if(right < n && heap[right] > heap[smallest]){
        smallest = right;
    }

    if(smallest != i){
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        heapDown(heap, n, smallest);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    for(int i = numsSize/2 - 1; i >= 0; i--){
        heapDown(nums, numsSize, i);
    }

    for(int i = numsSize-1; i > 0; i--){
        int temp = nums[0];
        nums[0] = nums[i];
        nums[i] = temp;

        heapDown(nums, i, 0);
        }
        *returnSize = numsSize;
        return nums;
}