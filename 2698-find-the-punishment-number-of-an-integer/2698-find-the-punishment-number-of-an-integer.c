bool check(char* s, int index, int target){
    int num = 0;

    if(s[index] == '\0'){
        return target == 0;
    }

    for(int i = index; s[i] != '\0'; i++){
        num = num * 10 + (s[i] - '0');

        if(num > target){
            break;
        }

        if(check(s, i+1, target - num)){
            return true;
        }
    }
    return false;
}

int punishmentNumber(int n) {
    int sum = 0;

    for(int i = 1; i <= n; i++){
        int square = i * i;
        char s[20];
        sprintf(s, "%d", square);

        if(check(s, 0, i)){
            sum += square;
        }
   }
   return sum;
}