class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int rows = matrix.size(), cols = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        int ans = 0;

        for(int x = 0; x < cols; x++){
            if(matrix[0][x] == '1'){
                ans = 1;
                dp[0][x] = 1;
            }
        }

        for(int y = 0; y < rows; y++){
            if(matrix[y][0] == '1'){
                ans = 1;
                dp[y][0] = 1;
            }
        }

        for(int x = 1; x < cols; x++){
            for(int y = 1; y < rows; y++){
                if(matrix[y][x] == '1'){
                    dp[y][x] = min({dp[y][x - 1], dp[y - 1][x - 1], dp[y - 1][x]}) + 1;
                }

                ans = max(ans, dp[y][x] * dp[y][x]);
            }
        }

        return ans;
    }
};