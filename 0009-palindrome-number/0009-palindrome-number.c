bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
    int temp = x;
    int length = (temp == 0) ? 1 : (int)floor(log10(temp)) + 1;
    int* array = (int*)malloc(length * sizeof(int));

    

    for (int i = length -1; i  >=0; i--){
        array[i] = temp % 10;
        temp /= 10;
    }

    for (int j = 0; j <length/2; j++){
            if (array[j] != array[length-1-j]){
                free(array);
                return false;
            }
    }
    free(array);
    return true;
}