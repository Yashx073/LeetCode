bool isPowerOfFour(int n) {
    if (n <= 0)
        return false;

    double x = log2(n);

    return x == floor(x) && ((int)x % 2 == 0);
}