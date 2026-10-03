bool checkValidString(char* s) {
    int n = strlen(s);

    int* arr = (int *)malloc(n * sizeof(int));
    int a = -1;

    int* star = (int *)malloc(n * sizeof(int));
    int st = -1;

    for(int i = 0; i < n; i++) {

        if(s[i] == '(') {
            arr[++a] = i;
        }
        else if(s[i] == '*') {
            star[++st] = i;
        }
        else {
            if(a > -1) {
                a--;
            }
            else if(st > -1) {
                st--;
            }
            else {
                free(arr);
                free(star);
                return false;
            }
        }
    }

    while(a > -1 && st > -1) {

        if(arr[a] > star[st]) {
            free(arr);
            free(star);
            return false;
        }

        a--;
        st--;
    }

    bool ans = (a == -1);

    free(arr);
    free(star);

    return ans;
}