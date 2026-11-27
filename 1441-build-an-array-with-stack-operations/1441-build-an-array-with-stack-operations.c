/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char** result = (char **)malloc(2 * n * sizeof(char*));
    int ptr = 0;
    int rtx = 0;

    for(int i = 1; i <= target[targetSize-1]; i++){
        if(i == target[rtx]){
            result[ptr] = malloc(6);
            strcpy(result[ptr++], "Push");
            rtx++;
        }
        else{
            result[ptr] = malloc(6);
            strcpy(result[ptr++], "Push");
            result[ptr] = malloc(6);
            strcpy(result[ptr++], "Pop");
        }
    }
    *returnSize = ptr;
    return result;
}