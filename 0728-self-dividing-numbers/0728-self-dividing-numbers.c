/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isD(int num){
    int temp = num;
    while(temp != 0){
        int rem = temp % 10;

        if(rem == 0 || num % rem != 0){
            return false;
        }

        temp /= 10;
    
    }
    return true;
}

int* selfDividingNumbers(int left, int right, int* returnSize) {
    
    int* result = (int *)malloc((right - left) * sizeof(int));
    *returnSize = 0;
    for(int i = left; i <= right; i++){
        if(isD(i)){
            result[(*returnSize)++] = i;
        }
    }
    return result;
}