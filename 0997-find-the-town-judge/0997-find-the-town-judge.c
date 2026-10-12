int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    if (n == 1 && trustSize == 0) {
        return 1;
    }
    int* check = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < trustSize; i++) {
        check[trust[i][0]]--;
        check[trust[i][1]]++;
    }
    int judge = -1;

    for (int i = 1; i <= n; i++) {
        if (check[i] == n - 1) {
            judge = i;
            break; 
        }
    }
    free(check);
    return judge;
}