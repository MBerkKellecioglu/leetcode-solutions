class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
       
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
    
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        
      
        for(int sz = 2; sz <= n; sz++) {
            for(int l = 0; l <= n - sz; l++) {
                int r = l + sz - 1;
                int score = 0;
                
                for(int split = l; split < r; split++) {
                    int left_score = prefix[split + 1] - prefix[l];
                    int right_score = prefix[r + 1] - prefix[split + 1];
                    
                    if(left_score > right_score) {
                        score = max(score, right_score + dp[split + 1][r]);
                    } 
                    else if(right_score > left_score) {
                        score = max(score, left_score + dp[l][split]);
                    } 
                    else {
                        score = max(score, left_score + max(dp[l][split], dp[split + 1][r]));
                    }
                }
                
                dp[l][r] = score;
            }
        }
        
        return dp[0][n - 1];
    }
};