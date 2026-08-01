int compare(const void* a, const void* b){
    int *x = *(int **)a;
    int *y = *(int **)b;

    if(x[0] != y[0]){
        return y[0] - x[0];
    }

    return x[1] - y[1];
}

int numberOfWeakCharacters(int** properties, int propertiesSize, int* propertiesColSize) {
    qsort(properties, propertiesSize, sizeof(int *), compare);

    int maxD = 0;
    int count = 0;

    for(int i = 0; i < propertiesSize; i++){
        if(properties[i][1] < maxD){
            count++;
        }
        else{
            maxD = properties[i][1];
        }
    }
    return count;
}