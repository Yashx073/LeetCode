/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char* seq, int* returnSize) {
    int n = strlen(seq);
    int* arr = (int *)malloc(n * sizeof(int));

    int d = 0;

    for(int i = 0; i < n; i++){
        if(seq[i] == '('){
            d++;
            arr[i] = d % 2;
        }
        else{
            arr[i] = d % 2;
            d--;
        }
    }
    *returnSize = n;
    return arr;
}