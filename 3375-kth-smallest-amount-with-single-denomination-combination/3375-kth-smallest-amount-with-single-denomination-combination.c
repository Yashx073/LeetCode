long long gcd(long long a , long long b){
    while(b != 0){
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long findKthSmallest(int* coins, int coinsSize, int k) {
    int n = coinsSize;
    int num_subsets = (1 << n) - 1;
    long long lcm[32768];
    int signs[32768];
    int idx = 0;

    long long min_coin = coins[0];
    for(int i = 1; i < n; i++){
        if(min_coin > coins[i]){
            min_coin = coins[i];
        }
    }

    for(int i = 1; i < (1 << n); i++){
        int count = 0;
        long long curr_lcm = 1;

        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                count++;
                long long coin = coins[j];
                curr_lcm = (curr_lcm / gcd(curr_lcm, coin)) * coin;
            }
        }
        lcm[idx] = curr_lcm;
        signs[idx] = (count % 2 == 1) ? 1 : -1;
        idx++;
    }

    long long left = 1;
    long long right = min_coin * k;

    while(left < right){
        long long mid = left + (right - left) / 2;
        long long cnt = 0;

        for(int i = 0; i < num_subsets; i++){
            cnt += signs[i] * (mid/lcm[i]);
        }
        if(cnt < k){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return left;
}