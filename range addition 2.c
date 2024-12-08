int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
    if (opsSize < 1) return m*n;
    int smallest_x = ops[0][0];
    int smallest_y = ops[0][1];
    for (int i = 0; i < opsSize; i++){
        if (ops[i][0] < smallest_x) smallest_x = ops[i][0];
        if (ops[i][1] < smallest_y) smallest_y = ops[i][1];
    }
    return smallest_x*smallest_y;
}
