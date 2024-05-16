class Solution {
public:
    int numTrees(int n){
        
        int sol = 0;

        vector<int> dp(20, 0);

        dp[0] = 1;

        dp[1] = 1;

        dp[2] = 2;

        if(n <= 2) return dp[n];

        for(int i = 3; i <= n; i++){
            dp[i] = calculate(dp, i);
        }



        return dp[n];
    }

    int calculate(vector<int>& dp, int n){
        
        int sol = 0;

        for(int i = 1; i <= n; i++){
            sol += dp[i - 1] * dp[n - i];
        }

        return sol;
    }
};