int compare(const void* a, const void* b){
    return (*(char *)a - *(char *)b);
}

char* sortVowels(char* s) {
    int n = strlen(s);
    int* index = (int *)malloc(n * sizeof(int));
    char* ch = (char *)malloc(n * sizeof(char));
    int in = 0;
    int c = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            index[in++] = i;
            ch[c++] = s[i];
        }
    }
    qsort(ch, c, sizeof(char), compare);

    for(int i = 0; i < c; i++){
        s[index[i]] = ch[i];
    }
    return s;
}