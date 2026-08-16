int maxSum(int** grid, int gridSize, int* gridColSize) {
    int row = gridSize;
    int col = *gridColSize;

    if(col < 3 || row < 3){
        return 0;
    }

    int max = INT_MIN;

    for(int i = 0; i < row - 2; i++){
        for(int j = 0; j < col - 2; j++){
            
            int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

            max = (max > sum) ? max : sum;
        }
    }   

    return max;
}