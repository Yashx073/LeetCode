int compare(const void* a, const void* b) {
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}

long long minSumSquareDiff(int* nums1, int nums1Size,
                           int* nums2, int nums2Size,
                           int k1, int k2) {
    int n = nums1Size;
    int* diff = malloc(n * sizeof(int));
    long long k = (long long)k1 + k2;
    int maxDiff = 0;

    for(int i = 0; i < n; i++) {
        diff[i] = abs(nums1[i] - nums2[i]);
        if(diff[i] > maxDiff) maxDiff = diff[i];
    }

    long long total = 0;
    for(int i = 0; i < n; i++) total += diff[i];

    if(k >= total) {
        free(diff);
        return 0;
    }

    int left = 0, right = maxDiff;

    while(left < right) {
        int mid = left + (right - left) / 2;
        long long need = 0;

        for(int i = 0; i < n; i++) {
            if(diff[i] > mid) need += diff[i] - mid;
        }

        if(need <= k) right = mid;
        else left = mid + 1;
    }

    int threshold = left;
    long long used = 0;

    for(int i = 0; i < n; i++) {
        if(diff[i] > threshold) {
            used += diff[i] - threshold;
            diff[i] = threshold;
        }
    }

    long long remaining = k - used;

    for(int i = 0; i < n && remaining > 0; i++) {
        if(diff[i] == threshold) {
            diff[i]--;
            remaining--;
        }
    }

    long long ans = 0;
    for(int i = 0; i < n; i++)
        ans += (long long)diff[i] * diff[i];

    free(diff);
    return ans;
}