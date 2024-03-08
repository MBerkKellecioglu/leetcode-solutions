class Solution {
public:
    int change(int amount, vector<int>& coins){

        int dp[coins.size()][amount + 1];


        for(int i = 0; i < coins.size(); i++) dp[i][0] = 1;

        for(int i = 1; i < amount + 1; i++){
            if(i % coins[0] == 0) dp[0][i] = 1;
            else dp[0][i] = 0;
        }

        for(int i = 1; i < coins.size(); i++){
            for(int j = 1; j < amount + 1; j++){
                dp[i][j] = (j - coins[i] >= 0) ? dp[i - 1][j] + dp[i][j - coins[i]] : dp[i - 1][j];                
            }
        }

        return dp[coins.size() - 1][amount];

    }
};