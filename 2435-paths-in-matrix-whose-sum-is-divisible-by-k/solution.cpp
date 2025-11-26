class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        int m = grid.size(), n = grid[0].size();

        int modulo = pow(10,9) + 7;

        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k, 0)));

        dp[m - 1][n - 1][grid[m - 1][n - 1] % k] = 1;

        for(int i = m - 1; i > -1; i--){
            for(int j = n - 1; j > -1; j--){

                for(int r = 0; r < k; r++){
                    int converted = (r + grid[i][j]) % k;
                    
                    dp[i][j][converted] += ((dp[i + 1][j][r] % modulo) + (dp[i][j + 1][r] % modulo)) % modulo;
                }
            }
        }

        return dp[0][0][0];
    }
};