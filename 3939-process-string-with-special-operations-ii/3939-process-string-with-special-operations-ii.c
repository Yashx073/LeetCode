char processStr(char* s, long long k) {
    long long len = 0;

    for(int i = 0; s[i]; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            len++;
        }
        else if(s[i] == '*'){
            if(len > 0){
                len--;
            }
        }
        else if(s[i] == '#'){
            if(len <= 1000000000000000000LL / 2){
                len *= 2;
            }
            else{
                len = 1000000000000000000LL;
            }
        }
        else if(s[i] == '%'){
            continue;
        }
    }

    if(k >= len){
        return '.';
    }   

    int n = strlen(s);

    for(int i = n-1; i >= 0; i--){
        if(s[i] >= 'a' && s[i] <= 'z'){
            if(k == len - 1){
                return s[i];
            }
            len --;
        }
        else if(s[i] == '*'){
            len++;
        }
        else if(s[i] == '#'){
            len /= 2;

            if(k >= len){
                k -= len;
            }
        }
        else if(s[i] == '%'){
            k = len - 1 - k;
        }
    }
    return '.';
}