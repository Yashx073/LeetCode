void reverse(char* s, int left, int right){
    while(left < right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

char* processStr(char* s) {
    int capacity = 16;
    char* result = (char *)malloc(capacity * sizeof(char));
    int len = 0;
    result[len] = '\0';
    int length = strlen(s);

    for(int i = 0; i < length; i++){
        if(s[i] == '*'){
            if(len > 0){
                len--;
                result[len] = '\0';
            }
        }
        else if(s[i] == '#'){
            int old = len;
            while(len + old + 1 > capacity){
                capacity *= 2;
                result = (char *)realloc(result, capacity * sizeof(char));
            }
            
            for(int j = 0; j < old; j++){
                result[len + j] = result[j];
            }
            len += old;
            result[len] = '\0';
        }
        else if(s[i] == '%'){
            reverse(result, 0, len - 1);
        }
        else{
            if(len + 2 > capacity){
                capacity *= 2;
                result = (char *)realloc(result, capacity * sizeof(char));
            }
            result[len++] = s[i];
            result[len] = '\0';
        }
    }
    return result;
}