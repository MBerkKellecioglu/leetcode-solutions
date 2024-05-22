class Solution {
public:
    int minimumTotal(vector<vector<int>>& levels) {
        
        vector<int> dp = levels.back();

        int n = dp.size() - 1;

        for(int i = levels.size() - 2; i > -1; i--){
            for(int j = 0; j < n; j++){
                dp[j] = levels[i][j] + min(dp[j], dp[j + 1]);
            }
            n--;
        }

        return dp[0];
    }
};