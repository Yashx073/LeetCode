int mult(int n){
    int temp = n;
    int prod = 1;
    while(temp != 0){
        int rem = temp % 10;
        prod = prod * rem;
        temp = temp / 10;
    }
    return prod;
}

int smallestNumber(int n, int t) {
    
    for(int i = n; i <= 100; i++){
        int temp = mult(i);
        if(temp % t == 0){
            return i;
        }
    }
    return -1;
}