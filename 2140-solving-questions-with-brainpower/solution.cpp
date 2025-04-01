using ll = long long;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        
        int n = q.size();
        ll ans = -1;

        vector<ll> dp(n + 1, 0);

        for(int i = n - 1; i > -1; i--){
            ll skip = dp[i + 1];
            ll solve = q[i][0];
            
            if(i + q[i][1] + 1 < n){
                solve += dp[i + q[i][1] + 1];
            }

            dp[i] = max(skip, solve);
        }

        return dp[0];
    }
};