char nextGreatestLetter(char* letters, int lettersSize, char target) {
    
    int* arr = (int *)malloc(lettersSize * sizeof(int));

    for(int i = 0; i < lettersSize; i++){
        arr[i] = letters[i];
    }

    int a = target;

    for(int i = 0; i < lettersSize; i++){
        if(arr[i] > a){
            return (char)arr[i];
        }
    }

    return (char)arr[0];

}