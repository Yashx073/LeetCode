bool checkDivisibility(int n) {
    int sum = 0;
    int product = 1;
    int temp = n;
    
    while(temp > 0){
        sum += temp % 10;
        temp /= 10;
    }

    temp = n;
    while(temp > 0){
        product *= temp % 10;
        temp /= 10;
    }

    int div = sum + product;

    if(n % div == 0){
        return true;
    }

    return false;

}