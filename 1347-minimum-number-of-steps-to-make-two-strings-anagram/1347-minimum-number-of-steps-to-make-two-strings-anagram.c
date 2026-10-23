int minSteps(char* s, char* t) {
    int freq[26] = {0};

    for(int i = 0; s[i] != '\0'; i++){
        freq[s[i] - 'a']++;
    }

    for(int i = 0; t[i] != '\0'; i++){
        freq[t[i] - 'a']--;
    }

    int count = 0;

    for(int i = 0; i < 26; i++){
        if(freq[i] > 0){
            count += freq[i];
        }
    }

    return count;
}