bool detectCapitalUse(char* word) {
    int len = strlen(word);
    int count = 0;
    for(int i = 0; i < len; i++){
        if(isupper((unsigned char)word[i])){
            count++;
        }
    }
    
    return (count == 0 || count == len || count == 1 && isupper((unsigned char)word[0]));
}