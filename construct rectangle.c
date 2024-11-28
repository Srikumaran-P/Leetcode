
int* constructRectangle(int area, int* returnSize) {
    int L = (int)sqrt(area); 
    int W;
    int *result = (int *)malloc(2 * sizeof(int));
    
    while (area % L != 0) {
        L--; 
     }
    W = area / L;
    
    result[0] = L >= W ? L : W;
    result[1] = L > W ? W : L;
    *returnSize = 2; 
   return result;
}
    
