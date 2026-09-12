bool checkPerfectNumber(int num) {
    
    if(num <= 1){
        return false;
    }

    int sum = 1;

    for(int i = 2; i < sqrt(num); i++){
        if(num % i == 0){
            int n = num / i;
            if(i != n){
                sum += i + n;
            }
            else{
                sum += i;
            }
        }
    }
    return (sum == num);
}