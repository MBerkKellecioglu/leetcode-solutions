class Solution {
public:
    int numDecodings(string s){

        vector<int> dp(s.size() + 1, 0);

        dp[s.size()] = 1;
        
        for(int i = s.size() - 1; i > -1; i--){

            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }
            else dp[i] = dp[i + 1];

            if(i + 1 < s.size() && (s[i] - 48)* 10 + s[i + 1] - 48 < 27) dp[i] += dp[i + 2];
        }

        return dp[0];
    }
};