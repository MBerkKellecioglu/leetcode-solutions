class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text2.size(), vector<int>(text1.size(), 0));

        if(text1[0] == text2[0]) dp[0][0] = 1;

        for(int i = 1; i < text1.size(); i++){
            if(text1[i] == text2[0] || dp[0][i - 1] == 1) dp[0][i] = 1;
        }

        for(int i = 1; i < text2.size(); i++){
            if(text1[0] == text2[i] || dp[i - 1][0] == 1) dp[i][0] = 1;
        }

        for(int i = 1; i < text2.size(); i++){
            for(int j = 1; j < text1.size(); j++){
                dp[i][j] = (text1[j] == text2[i]) ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[text2.size() - 1][text1.size() - 1];
    }
};