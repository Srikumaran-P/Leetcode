bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;
    for(int i = 0;i<flowerbedSize && n>0;i++)
    {
        // Check if the current position is empty and neighbors are safe
        if(flowerbed[i] == 0 &&
            (i ==0 || flowerbed[i-1] == 0) &&
            ((i == flowerbedSize -1) || (flowerbed[i+1] == 0)))
        {
            flowerbed[i] = 1; //plant a flower
            n--;              // Decrement the number of flowers to plant
        }
    }
    //return true if all flowers are planted , false otherwise
    return n ==0;
}
