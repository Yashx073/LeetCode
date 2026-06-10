int lengthOfLastWord(char* s) {
    int size = strlen(s);
    int count = 0;
    int i = size-1;

    while(i>=0 &&s[i] == ' '){
        i--;
    }
    while(i>=0 && s[i] != ' '){
        count++;
        i--;
    }
    return count;
}