int maxProfit(int* prices, int pricesSize) {
    int min = prices[0];
    int max = 0;
    int profit = 0;
    for(int i = 0; i < pricesSize; i++){
        if(min > prices[i]){
            min = prices[i];
        }

        profit = prices[i] - min;

        if(profit > max){
            max = profit;
        }
    }
    return max;
}