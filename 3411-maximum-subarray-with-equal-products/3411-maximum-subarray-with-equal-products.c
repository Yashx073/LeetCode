long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a; // nums[i] >= 1, so a is always positive
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int maxLength(int* nums, int numsSize) {
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        long long prod = 1;
        long long g = 0;
        long long l = 1;

        for (int j = i; j < numsSize; j++) {
            prod *= nums[j];
            g = gcd(g, nums[j]);
            l = lcm(l, nums[j]);

            if (prod == l * g) {
                int len = j - i + 1;
                if (len > ans) ans = len;
            }

            if (prod > 25200) break;
        }
    }

    return ans;
}