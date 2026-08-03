int countTriples(int n) {
    int count = 0;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j < n; j++){
            double ans = (pow(i,2)+pow(j,2));
            ans = sqrt(ans);
            if(ans <= n && ans == (int)ans){
                count += 2;
            }
        }
    }
    return count;
}