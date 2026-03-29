bool isValid(char* s) {
     int l = strlen(s);
    #define MAX_SIZE l+1
    char stack[MAX_SIZE];
    int top  = -1;
   
    int count;



    for (int i = 0; i < l; i++){
        if(s[i] == '('){
            top ++;
            stack[top] = '(';
        }
        else if(s[i] == '['){
            top ++;
            stack[top] = '[';
        }
        else if(s[i] == '{'){
            top ++;
            stack[top] = '{';
        }
        else if(s[i] == ')'){
            if(top == -1 || stack[top] != '(')
                return false;
            top --;
        }
        else if(s[i] == ']'){
            if(top == -1 || stack[top] != '[')
                return false;
            top --;
        }
        else if(s[i] == '}'){
            if(top == -1 || stack[top] != '{')
                return false;
            top --;
        }
        else{
            return false;
        }
    }
    return top == -1;
}