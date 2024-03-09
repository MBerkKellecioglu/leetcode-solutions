class Solution {
public:
    int numDistinct(string s, string t){
        if(s.size() < t.size()) return 0;

        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));

        return dfs(dp, s, t, 0, 0);
    }

    int dfs(vector<vector<int>>& dp, string& s, string& t, int s_ind, int t_ind){
        
        if(t_ind >= t.size()) return 1;
        
        if(s_ind >= s.size()) return 0;

        if(dp[s_ind][t_ind] != -1) return dp[s_ind][t_ind];

        int tmp1 = dfs(dp, s, t, s_ind + 1, t_ind);
        int tmp2 = 0;

        if(s[s_ind] == t[t_ind]) tmp2 = dfs(dp, s, t, s_ind + 1, t_ind + 1);

        return dp[s_ind][t_ind] = tmp1 + tmp2;
    }
};