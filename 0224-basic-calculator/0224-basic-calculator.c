int calculate(char* s) {
    
    long long result = 0;
    long long sign = 1;
    long long num = 0;
    long long* arr = malloc(strlen(s) * sizeof(long long));
    int top = -1;

    for(int i = 0; i < strlen(s); i++){

        char ch = s[i];

        if(isdigit(ch)){
            num = num * 10 + (ch - '0');
        }
        else if(ch == '+'){
            result += sign * num;

            num = 0;
            sign = 1;
        }
        else if(ch == '-'){
            result += sign * num;

            num = 0;
            sign = -1;
        }
        else if(ch == '('){
            arr[++top] = result;
            arr[++top] = sign;

            result = 0;
            sign = 1;
        }
        else if(ch == ')'){
            result += sign * num;
            num = 0;

            int prevSign = arr[top--];
            int prevResult = arr[top--];

            result = prevResult + prevSign * result ;
        }
    }
    return (int)(result + sign * num);
}