int compare(const void* a, const void* b){
    return (*(int *)b - *(int *)a);
}

long long pickGifts(int* gifts, int giftsSize, int k) {
    long long sum = 0;
    

    for(int i = 0; i < k; i++){
        qsort(gifts, giftsSize, sizeof(int), compare);
        gifts[0] = sqrt(gifts[0]);
    }

    for(int i = 0; i < giftsSize; i++){
        sum += gifts[i];
    }
    return sum;
}