int scoreOfParentheses(char* s) {
    int n = strlen(s);
    int decl = 0;
    int count = 0;

    for(int i = 0; i < n; i++){
        char ch = s[i];
        if(ch == '('){
            decl++;
        }
        else if(ch == ')'){
            decl--;

            if(s[i - 1] == '(') {
                count += 1 << decl;
            }
        }

    }
    return count;
}