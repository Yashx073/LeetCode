int compare(const void* a, const void* b) {
    return (*(int *)b - *(int *)a);
}

int maximumSwap(int num) {

    int temp = num;
    int count = 0;

    while (temp != 0) {
        count++;
        temp /= 10;
    }

    int* arr = malloc(count * sizeof(int));
    int* sorted = malloc(count * sizeof(int));

    temp = num;
    for (int i = count - 1; i >= 0; i--) {
        arr[i] = temp % 10;
        sorted[i] = arr[i];
        temp /= 10;
    }

    qsort(sorted, count, sizeof(int), compare);

    for (int i = 0; i < count; i++) {

        if (arr[i] != sorted[i]) {

            int j = count - 1;

            while (arr[j] != sorted[i])
                j--;

            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;

            break;
        }
    }

    int result = 0;

    for (int i = 0; i < count; i++) {
        result = result * 10 + arr[i];
    }

    free(arr);
    free(sorted);

    return result;
}