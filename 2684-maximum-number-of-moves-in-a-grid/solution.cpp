class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size();

        vector<vector<bool>> dp(row, vector<bool>(col, false));

        int ans = 0;

        for(int y = 0; y < row; y++){
            dp[y][0] = true;
        }

        for(int x = 1; x < col; x++){
            /* this flag is for checking whether you can move onto the next collumn*
               if you pay attention how we can move, we actually iterate collumn by collumn*/
            bool flag = false;

            for(int y = 0; y < row; y++){
                if(dp[y][x - 1] && grid[y][x] > grid[y][x - 1]){
                    dp[y][x] = true;
                    flag = true;
                }
                else if(y - 1 > -1 && dp[y - 1][x - 1] && grid[y][x] > grid[y - 1][x - 1]){
                    dp[y][x] = true;
                    flag = true;
                }
                else if(y + 1 < row && dp[y + 1][x - 1] && grid[y][x] > grid[y + 1][x - 1]){
                    dp[y][x] = true;
                    flag = true;
                }
            }

            if(!flag){
                return ans;
            }
            else ans++;
        }

        return ans;
    }
};