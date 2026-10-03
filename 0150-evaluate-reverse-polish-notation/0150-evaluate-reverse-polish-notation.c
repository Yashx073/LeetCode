int evalRPN(char** tokens, int tokensSize) {
    int* arr = (int *)malloc(tokensSize * sizeof(int));
    int top = -1;
    int sum = 0;

    for(int i = 0; i < tokensSize; i++) {

        if(strcmp(tokens[i], "+") == 0 ||
           strcmp(tokens[i], "-") == 0 ||
           strcmp(tokens[i], "*") == 0 ||
           strcmp(tokens[i], "/") == 0) {

            int b = arr[top--];
            int a = arr[top];

            if(strcmp(tokens[i], "+") == 0) {
                sum = a + b;
            }
            else if(strcmp(tokens[i], "-") == 0) {
                sum = a - b;
            }
            else if(strcmp(tokens[i], "*") == 0) {
                sum = a * b;
            }
            else {
                sum = a / b;
            }

            arr[top] = sum;
        }
        else {
            arr[++top] = atoi(tokens[i]);
        }
    }

    int ans = arr[top];

    free(arr);

    return ans;
}