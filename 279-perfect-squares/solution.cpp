class Solution {
public:
    int numSquares(int n) {
        
        vector<int> perfect;
        vector<int> dp(n + 1, INT_MAX);

        int ans = 0;

        dp[1] = 1;
        dp[0] = 0;

        for(int i = 1; i <= sqrt(n); i++){
            if(i * i <= n) perfect.push_back(i * i);
        }

        for(int i = 2; i < n + 1; i++){
            for(int p : perfect){
                if(i - p >= 0) dp[i] = min(dp[i], dp[i - p] + 1);
            }
        }

        return dp[n];
    }
};