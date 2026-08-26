int sum(int n){
    int sum = 0;
    while(n > 0 ){
        int temp = n;
        temp = temp % 10;
        sum += temp;
        n = n / 10;
    }
    return sum;
}

int addDigits(int num) {
    while(num >= 10){
        num = sum(num);
    }
    return num;
}