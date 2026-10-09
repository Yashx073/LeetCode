int minInsertions(char* s) {
    int need = 0;
    int result = 0;

    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '('){
            if(need  % 2 != 0){
                need--;
                result++;
            }
            need += 2;
        }
        else{
            need--;

            if(need < 0){
                result++;
                need = 1;
            }
        }
    }
    return need + result;
}