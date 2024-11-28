int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int perimeter =0;
    for(int i=0; i<gridSize; i++) {
        for(int j=0; j< *gridColSize; j++) {
            if(grid[i][j] == 1) {
                perimeter +=4;
                if(i>0 && grid[i-1][j]==1)
                        perimeter--;
                if(i<gridSize-1 && grid[i+1][j]==1)
                        perimeter--;
                if(j>0 && grid[i][j-1]==1)
                        perimeter--;
                if(j< *gridColSize -1 && grid[i][j+1]==1)
                        perimeter--;
            }
        }
    }
    return perimeter;
}
