void push(char* arr, char s){

}

int longestValidParentheses(char* s) {
    int n = strlen(s);
    int* arr = (int *)malloc((n+1) * sizeof(int));
    int count = 0;
    int max = 0;
    arr[0] = -1;

    for(int i = 0; i < n; i ++){
        if(s[i] == '('){
            arr[++count] = i;
        }
        else{
            count--;
            if(count == -1){
                arr[++count] = i;
            }
            else{
                int len = i-arr[count];
                if(max < len){
                    max = len;
                }
            }
        }
    }
    free(arr);
    return max;
}