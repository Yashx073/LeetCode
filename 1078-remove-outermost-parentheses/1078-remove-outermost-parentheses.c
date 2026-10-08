char* removeOuterParentheses(char* s) {
    int n = strlen(s);
    char* result = malloc(n * sizeof(char));
    int pos = 0;
    int balance = 0;

    for(int i = 0; i < n; i++) {

        if(s[i] == '(') {
            balance++;

            if(balance > 1)
                result[pos++] = s[i];
        }
        else {
            balance--;

            if(balance > 0)
                result[pos++] = s[i];
        }
    }

    result[pos] = '\0';

    return result;
}