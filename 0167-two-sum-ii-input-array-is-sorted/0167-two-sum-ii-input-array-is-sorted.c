/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* num = (int *)malloc(2 * sizeof(int));

    int low = 0;
    int high = numbersSize - 1;

    while(low < high){
        int sum = numbers[low] + numbers[high];
        if(sum == target){
        num[0] = low + 1;
        num[1] = high + 1;
        *returnSize = 2;
        return num;
        }
        else if(sum < target){
            low++;
        }
        else{
            high--;
        }
    }
    *returnSize = 0;
    return NULL;
}