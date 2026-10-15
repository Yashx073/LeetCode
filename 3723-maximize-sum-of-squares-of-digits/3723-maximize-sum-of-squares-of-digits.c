char* maxSumOfSquares(int num, int sum) {
    if((num * 9) < sum) return "";

    char* res = (char *)malloc((num+1) * sizeof(char));

    for(int i = 0; i < num; i++){
        if(sum >= 9){
            res[i] = '0' + 9;
            sum -= 9;
        }
        else{
            res[i] = '0' + sum;
            sum = 0;
        }
    }

    if(sum){
        res[0] = '\0';
    }
    else{
        res[num] = '\0';
    }
    return res;
}