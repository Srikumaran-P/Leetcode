/* Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    if (matSize*matColSize[0] != r*c) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }

    printf("%d %d", matSize, matColSize[0]);

    int *cs = (int *)malloc(r * sizeof(int));
    for (int i=0; i<r; i++) {
        cs[i] = c;
    }

    *returnSize = r;
    *returnColumnSizes = cs;

    int **reshaped_mat = (int **)malloc(r * sizeof(int *)); 
    for (int i = 0; i < r; i++) {
        reshaped_mat[i] = (int *)malloc(c * sizeof(int));
    }

    int d = 0;

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            reshaped_mat[i][j] = mat[d/matColSize[0]][d%matColSize[0]];
            d++;
        }
    }
    return reshaped_mat;
    
}
