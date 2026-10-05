bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    int* arr = (int *)malloc(pushedSize * sizeof(int));
    int top = -1;
    int j = 0;
    for(int i = 0; i < pushedSize; i++){
        arr[++top] = pushed[i];
        while(top != -1 &&j < poppedSize && arr[top] == popped[j]){
            top--;
            j++;
        }
    }
    return j == poppedSize;
}