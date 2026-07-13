/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 int compare(const void *a, const void *b){
    return (*(int *)b - *(int *)a);
 }

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;
    int *sort = (int *)malloc(scoreSize * sizeof(int));
    char **placement = (char **)malloc(scoreSize * sizeof(char *));

    for(int i = 0; i < scoreSize; i++){
        sort[i] = score[i];
    }

    qsort(sort, scoreSize, sizeof(int), compare);

    for(int i = 0; i < scoreSize; i++){
        int rank = 0;

        while(sort[rank] != score[i]){
            rank++;
        }

        if(rank == 0){
            placement[i] = "Gold Medal";
        }
        else if(rank == 1){
            placement[i] = "Silver Medal";
        }
        else if(rank == 2){
            placement[i] = "Bronze Medal";
        }
        else{
            char * str = (char *)malloc(12 * sizeof(char));
            sprintf(str, "%d", rank + 1);
            placement[i] = str;
        }
    }
    free(sort);
    return placement;
}