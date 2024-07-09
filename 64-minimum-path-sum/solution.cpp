class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size() - 1;

        int n = grid[0].size() - 1;

        for(int i = n - 1; i > -1; i--){
            grid[m][i] += grid[m][i + 1];
        }

        for(int i = m - 1; i > -1; i--){
            grid[i][n] += grid[i + 1][n];
        }


        for(int i = m - 1; i > -1; i--){
            for(int j = n - 1; j > -1; j--){
                grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
            }
        }

        return grid[0][0];
    }
};