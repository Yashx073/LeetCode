int countPrimes(int n) {
    if (n <= 2)
        return 0;

    char *isPrime = malloc(n * sizeof(char));

    // Initially mark only odd numbers as prime
    for (int i = 3; i < n; i += 2)
        isPrime[i] = 1;

    isPrime[2] = 1;
    isPrime[0] = 0;
    isPrime[1] = 0;

    for (int i = 3; i * i < n; i += 2) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += 2 * i)
                isPrime[j] = 0;
        }
    }

    int count = 1;  

    for (int i = 3; i < n; i += 2) {
        if (isPrime[i])
            count++;
    }

    free(isPrime);

    return count;
}