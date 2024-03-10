class Solution {
public:
    bool isInterleave(string s1, string s2, string s3){

        if(s1.size() + s2.size() != s3.size()) return false;
        
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        return dfs(dp, s1, s2, s3, 0, 0);
    }

    bool dfs(vector<vector<int>>& dp, string& s1, string& s2, string& s3, int ptr1, int ptr2){

        if(ptr1 >= s1.size() && ptr2 >= s2.size()) return true;
        
        if(dp[ptr1][ptr2] != -1) return dp[ptr1][ptr2];
        
        bool tmp1 = false;
        bool tmp2 = false;
        
        if(ptr1 < s1.size() && s1[ptr1] == s3[ptr1 + ptr2]) tmp1 = dfs(dp, s1, s2, s3, ptr1 + 1, ptr2);
        if(ptr2 < s2.size() && s2[ptr2] == s3[ptr1 + ptr2]) tmp2 = dfs(dp, s1, s2, s3, ptr1, ptr2 + 1);

        return dp[ptr1][ptr2] = tmp1 || tmp2;
    }
};