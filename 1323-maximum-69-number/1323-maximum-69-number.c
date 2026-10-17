int maximum69Number (int num) {
    char s[6];
    sprintf(s, "%d", num);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '6') {
            s[i] = '9';
            break;
        }
    }
    return atoi(s);
}