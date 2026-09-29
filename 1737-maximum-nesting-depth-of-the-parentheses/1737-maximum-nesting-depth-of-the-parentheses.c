int maxDepth(char* s) {
    int count = 0;
    int result = 0;
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            count++;
        }
        else if(s[i] == ')'){
            count--;
        }
        if(result < count){
            result = count;
        }
    }
    return result;
}