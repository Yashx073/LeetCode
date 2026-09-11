bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    
    int i = 0;

    while(i < flowerbedSize && n > 0){
        if(flowerbed[i] == 0 && (i == 0 ||flowerbed[i-1] != 1) && ( i == flowerbedSize - 1 ||flowerbed[i+1] != 1)){
            flowerbed[i] = 1;
            n--;
        }
        i++;
    }
    
    return (n == 0);
}