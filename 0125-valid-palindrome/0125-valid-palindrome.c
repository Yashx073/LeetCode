bool isPalindrome(char* s) {
    char clean[100001];
    int k = 0;

    for(int i = 0; s[i] != '\0'; i++){
        if(isalnum(s[i])){
            clean[k++] = tolower(s[i]);
        }
    }
    clean[k] ='\0';

    int j = strlen(clean)-1;
    int  i = 0;
    while(  i<j ){
        if(clean[i] != clean[j]){
        return false;
        }
        i++;
        j--;
    }
    return true;
}