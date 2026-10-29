char* removeStars(char* s) {
    
    char* ch = (char *)malloc((strlen(s)+1) * sizeof(char));
    int n = 0;

    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] != '*'){
            ch[n++] = s[i];
        }
        else if(n > 0){
            n--;
        }
    }
    ch[n] = '\0';
    return ch;
}