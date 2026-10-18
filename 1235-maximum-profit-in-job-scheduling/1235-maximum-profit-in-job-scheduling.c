struct Job{
    int start;
    int end;
    int profit;
};

int compare(const void* a, const void* b){
    struct Job* jobA = (struct Job*)a;
    struct Job* jobB = (struct Job*)b;

    if(jobA->end != jobB->end){
        return jobA->end - jobB->end;
    }
    else{
        return jobA->start - jobB->start;
    }
}

int binarySearch(struct Job* jobs, int index){
    int low = 0;
    int high = index - 1;
    int valid = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(jobs[mid].end <= jobs[index].start){
            valid = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return valid;
}

int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize) {
  int n = startTimeSize;
  struct Job* jobs = (struct Job*)malloc(n * sizeof(struct Job));
  for(int i = 0; i < n; i++){
    jobs[i].start = startTime[i];
    jobs[i].end = endTime[i];
    jobs[i].profit = profit[i];
  }  

    qsort(jobs, n, sizeof(struct Job), compare);

    int* dp = (int *)malloc(n * sizeof(int));
    dp[0] = jobs[0].profit;

    for(int i = 1; i < n; i++){
        int incP = jobs[i].profit;
        int idx = binarySearch(jobs, i);
        if(idx != -1){
            incP += dp[idx];
        }
        int exclP = dp[i-1];
        dp[i] = (incP > exclP)? incP : exclP;
    }

    int maxProfit = dp[n-1];
    free(jobs);
    free(dp);
    return maxProfit;

}