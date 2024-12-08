int distributeCandies(int* candyType, int candyTypeSize) {
    int type[200001] = {0};
    int offset = 100000;
    int i;
    int maxTypes = candyTypeSize / 2;
    int currType = 0;

    for(i = 0; i < candyTypeSize; i++){
        if(type[candyType[i] + offset] == 0){
            type[candyType[i] + offset] = 1;
            currType++;
        }

        if(currType == maxTypes){
            return maxTypes;
        }
    }

    return currType;
}
