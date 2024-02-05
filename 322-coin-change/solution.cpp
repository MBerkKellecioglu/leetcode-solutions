class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
        if(amount == 0) return 0;

        vector<vector<int>> dp(coins.size(), vector<int>(amount, 0));

        for(int i = 0; i < amount; i++) dp[0][i] = ( (i + 1) % coins[0] == 0) ? (i + 1) / coins[0] : -1; 
        
        for(int x = 1; x < coins.size(); x++){
            for(int y = 0; y < amount; y++){
                if(y + 1 - coins[x] < 0) dp[x][y] = dp[x - 1][y];        
                else if(y + 1 - coins[x] == 0) dp[x][y] = 1;
                else{
                    if(dp[x][y - coins[x]] == -1 && dp[x - 1][y] == -1) dp[x][y] = -1;
                    else if(dp[x][y - coins[x]] == -1) dp[x][y] = dp[x - 1][y];
                    else if(dp[x - 1][y] == -1) dp[x][y] = dp[x][y - coins[x]] + 1;
                    else dp[x][y] = min(dp[x][y - coins[x]] + 1, dp[x - 1][y]);
                }
            }
        }

        int ans = INT_MAX;

        for(int i = 0; i < coins.size(); i++) if(dp[i][amount - 1] != -1) ans = min(ans, dp[i][amount - 1]);
        
        if(ans == INT_MAX) return - 1;

        return ans;
    }
};