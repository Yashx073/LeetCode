char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0){
        return "";
    }
    int j = 0;
        for(int i = 0; i < strsSize; i++){
            j = 0;
            while(strs[0][j] && strs[i][j] && strs[0][j] == strs[i][j]){
                j++;
            }
        strs[0][j] = '\0';
        }
    return strs[0];
}