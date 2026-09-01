char* removeKdigits(char* num, int k) {
    int n = strlen(num);
    char* stack = (char *)malloc((n+2) * sizeof(char));
    int top = 0;
    
    if(k >= n){
        stack[0] = '0';
        stack[1] = '\0';
        return stack;
    }

    if(k == 0){
        return num;
    }

    for(int i = 0; i < n; i++){
        while(top > 0 && k > 0 && stack[top-1] > num[i]){
            top--;
            k--;
        }
        stack[top++] = num[i];
    }

    stack[top] = '\0';

    while(k > 0){
        top--;
        k--;
    }

    int start = 0;

    while(start < top && stack[start] == '0'){
        start++;
    }

    if(start == top){
        stack[0] = '0';
        stack[1] = '\0';
        return stack;
    }
    int j = 0;

    while(start < top){
        stack[j++] = stack[start++];
    }

    stack[j] = '\0';

    return stack;

}