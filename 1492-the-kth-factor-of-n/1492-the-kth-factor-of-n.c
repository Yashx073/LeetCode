int kthFactor(int n, int k) {
    int* arr = (int *)malloc((n+1) * sizeof(int));
    int ptr = 0;

    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            arr[ptr++] = i;
        }
    }

    if(k > ptr){
        return -1;
    }

    return arr[k-1];
}