int climbStairs(int n) {
    int a = 1;
    int b = 2;

    if(n <=2){
        b = n;
    }
     else{
    for (int i = 3; i <= n; i++){
        int c = a + b;
        a = b;
        b = c;
    }}
    return b;
}