int divide(int dividend, int divisor) {
    long long q = 0;

    if(dividend == INT_MIN && divisor == -1){
        return INT_MAX;
    }

    long long dvd = labs((long long) (dividend));
    long long dvs = labs((long long) (divisor));

    while(dvd >= dvs){

        long long temp = dvs;
        long long multiple = 1;

        while((temp << 1) <= dvd){
            temp <<= 1;
            multiple <<= 1;
        }

        dvd -= temp;
        q += multiple;
    }

    if((dividend > 0) ^ (divisor > 0)){
        q = -q;
    }

    return q;
}