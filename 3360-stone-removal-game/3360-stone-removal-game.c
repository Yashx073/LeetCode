bool canAliceWin(int n) {
    int root = 10;
    while(1){
        if(n >= root){
            n -= root;
            root--;
        }
        else{
            return false;
        }

        if(n >= root){
            n -= root;
            root--;
        }
        else{
            return true;
        }
    }
    return false;
}