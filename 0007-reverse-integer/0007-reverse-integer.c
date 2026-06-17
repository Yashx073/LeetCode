int reverse(int x){
    int rem = 0;
    long rev = 0;

    while(x != 0){
        rem = x % 10;
        rev = rev * 10 + rem;
        x /= 10;
    }
    if(rev > INT_MIN && rev < INT_MAX){
        return rev;
    }
    else{
        return 0;
    }
}