class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        if(obstacleGrid[m - 1][n - 1] == 1) return 0;

        int flag = 0;
        
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        
        for(int i = n - 1; i > -1; i--){
            if(obstacleGrid[m - 1][i] == 1) flag = 1;

            if(flag) dp[m - 1][i] = 0;
            else dp[m - 1][i] = 1;
        } 
        
        flag = 0;

        for(int i = m - 1; i > -1; i--){
            if(obstacleGrid[i][n - 1] == 1) flag = 1;
            if(flag) dp[i][n - 1] = 0;
            else dp[i][n - 1] = 1;
        }
        
        for(int i = m - 2; i > -1; i--){
            for(int j = n - 2; j > -1; j--){
                if(obstacleGrid[i][j] != 1) dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                else dp[i][j] = 0;
            }
        }

        return dp[0][0];

    }
};