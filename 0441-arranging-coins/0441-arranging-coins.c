int arrangeCoins(int n) {
    int res = 0;
    int i = 1;
    while(n > 0){
        n -= i;
        if(n >= 0){
            res++;
        }
        i++;
    }
    return res;
}