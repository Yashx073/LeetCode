char* minRemoveToMakeValid(char* s) {
    int n = strlen(s);
    char* arr = (char *)malloc((n+1) * sizeof(char));
    int balance = 0;
    int top = -1;

    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            balance++;
            arr[++top] = '(';
        } 
        else if(s[i] == ')'){
            if(balance == 0){
                continue;
            }
            balance--;
            arr[++top] = s[i];
        }
        else{
            arr[++top] = s[i];
        }
    }
    for(int i = top; i >= 0 && balance > 0; i--){
        if(arr[i] == '('){
            for(int j = i; j < top; j++){
                arr[j] = arr[j+1];
            }
            top--;
            balance--;
        }
    }
    arr[top+1] = '\0';
    return arr;
}