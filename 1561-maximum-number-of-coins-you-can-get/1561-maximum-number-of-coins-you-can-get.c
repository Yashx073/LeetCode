int compare(const void* a, const void* b){
    return (*(int *)b - *(int *)a);
}

int maxCoins(int* piles, int pilesSize) {

    if(pilesSize % 3 != 0){
        return 0;
    }

    qsort(piles, pilesSize, sizeof(int), compare);

    int coin = 0;
    int last = pilesSize - 1;
    for(int i = 0; i < last; i+=2){
        piles[i] = 0;
        coin += piles[i+1];
        piles[i+1] = 0;
        piles[last--] = 0;
    }

    return coin;

}