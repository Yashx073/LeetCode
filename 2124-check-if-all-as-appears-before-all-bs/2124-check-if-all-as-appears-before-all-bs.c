bool checkString(char* s) {
    int a = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 'b'){
            a = 1;
        }
        if(s[i] == 'a' && a == 1){
            return false;
        }
    }
    return true;
}