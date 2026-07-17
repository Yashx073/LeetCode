int compare(const void *a, const void *b){
    return (*(int *)b - *(int *)a);
}

int fillCups(int* amount, int amountSize) {
    int time = 0;
    while(amount[0] || amount[1] || amount[2]){
        qsort(amount, amountSize, sizeof(int), compare);

        if(amount[0] > 0){
            amount[0]--;
        }

        if(amount[1] > 0){
            amount[1]--;
        }

        time++;
    }   
    return time;
}