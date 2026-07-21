int compare(const void* a, const void* b){
    return (*(int *)b - *(int *)a);
}

int lastStoneWeight(int* stones, int stonesSize) {
    
    for(int i = 0; i < stonesSize - 1; i++){
        qsort(stones, stonesSize, sizeof(int), compare);
        if(stones[0] && stones[1]){
            stones[0] -= stones[1];
            stones[1] -= stones[1];
        }
    }
    return stones[0];
}