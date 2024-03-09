class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix){

        int m = matrix.size(), n = matrix[0].size(), sol = INT_MIN;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] == -1) dfs(matrix, dp, i, j, m, n, sol); 
            }
        }

        return sol;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y, int& m, int& n, int& sol){

        if(dp[x][y] != -1) return dp[x][y];

        int path = INT_MIN;

        if(x + 1 < m && matrix[x][y] < matrix[x + 1][y]) path = max(path, 1 + dfs(matrix, dp, x + 1, y, m, n, sol));
        if(x - 1 > -1 && matrix[x][y] < matrix[x - 1][y]) path = max(path, 1 + dfs(matrix, dp, x - 1, y, m, n, sol));
        if(y + 1 < n && matrix[x][y] < matrix[x][y + 1]) path = max(path, 1 + dfs(matrix, dp, x, y + 1, m, n, sol));
        if(y - 1 > -1 && matrix[x][y] < matrix[x][y - 1]) path = max(path, 1 + dfs(matrix, dp, x, y - 1, m, n, sol));

        dp[x][y] = (path == INT_MIN) ? 1 : path;

        sol = max(sol, dp[x][y]);

        return dp[x][y];
    }
};