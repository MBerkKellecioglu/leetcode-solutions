class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<bool> dp(s.size() + 1, false);

        dp[s.size()] = true;

        for(int i = s.size() - 1; i > -1; i--){
            for(string& word : wordDict){
                if(i + word.size() <= s.size()){
                    string tmp = s.substr(i, word.size());
                    if(tmp == word) dp[i] = dp[i + word.size()];
                }
                if(dp[i]) break;
            }
        }

        return dp[0];
    }
};