class Solution {
public:
    bool isMatch(string s, string p) {

        int s_size = s.size(), p_size = p.size();
        
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1)); // -1 means it is not checked

        return dfs(dp, s, p, 0, 0, s_size, p_size);
    }

    bool dfs(vector<vector<int>>& dp, string& s, string& p, int sp, int pp, int& s_size, int& p_size){ 
        
        // sp -> s pointer, pp -> p pointer

        if(sp >= s_size && pp >= p_size) return true;
        
        if(pp >= p_size) return false;
        
        if(dp[sp][pp] != -1) return dp[sp][pp];

        bool not_pick = false, pick = false;

        if(pp + 1 < p_size && p[pp + 1] == '*'){
            not_pick = dfs(dp, s, p, sp, pp + 2, s_size, p_size);

            if(sp < s_size && (p[pp] == '.' || s[sp] == p[pp]) ) pick = dfs(dp, s, p, sp + 1, pp, s_size, p_size);

            return dp[sp][pp] = pick || not_pick;
        }
        
        if(sp < s_size && (p[pp] == '.' || s[sp] == p[pp]) ){
            return dp[sp][pp] = dfs(dp, s, p, sp + 1, pp + 1, s_size, p_size);
        }

        return dp[sp][pp] = 0;
    }
};