char* reverseVowels(char* s) {
    int n = strlen(s);
    int left = 0;
    int right = n - 1;

    while(left <= right){
        while (left < right && strchr("aeiouAEIOU", s[left]) == NULL){
            left++;
        }

        while (left < right && strchr("aeiouAEIOU", s[right]) == NULL){
            right--;
        }

        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    return s;
}