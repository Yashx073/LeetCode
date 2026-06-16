bool isSubsequence(char* s, char* t) {
    int iSize = strlen(s);
    int jSize = strlen(t);
    int i = 0, j = 0;


    if(iSize == 0){
        return true;
    }

    while( j < jSize){
        if(s[i] == t[j]){
            i++;
        }
        j++;
    }
    return s[i] == '\0';
}