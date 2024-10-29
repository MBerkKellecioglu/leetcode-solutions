class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int row = matrix.size(), col = matrix[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 0));

        int ans = 0;

        for(int y = 0; y < row; y++){
            dp[y][0] = matrix[y][0];

            ans += dp[y][0];
        }

        for(int x = 1; x < col; x++){
            for(int y = 0; y < row; y++){
                if(matrix[y][x]){
                    int cell1 = 0, cell2 = 0, cell3 = 0;

                    cell1 = dp[y][x - 1];

                    cell2 = (y - 1 > -1) ? dp[y - 1][x] : 0;

                    cell3 = (y - 1 > - 1) ? dp[y - 1][x - 1] : 0;

                    dp[y][x] = min({cell1, cell2, cell3}) + 1;

                    ans += dp[y][x]; 
                }
            }
        }

        return ans;
    }
};