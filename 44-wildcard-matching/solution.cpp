class Solution {
public:
    bool isMatch(string s, string p) {
        
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));

        return memo(dp, s, p, 0, 0);
    }

    bool memo(vector<vector<int>>& dp, string& s, string& p, int sp, int pp){

        if(sp >= s.size() && pp >= p.size()){
            return true;
        }

        if(pp >= p.size()) return false;

        if(sp >= s.size()){
            for(int i = pp; i < p.size(); i++){
                if(p[i] != '*') return false;
            }

            return true;
        }
        
        if(dp[sp][pp] != -1) return dp[sp][pp];

        bool same = false;

        bool pick = false;

        bool not_pick = false;

        if(s[sp] != p[pp] && p[pp] != '?' && p[pp] != '*'){
            return false;
        }
 
        if(sp < s.size() && (s[sp] == p[pp] || p[pp] == '?')){
            same = memo(dp, s, p, sp + 1, pp + 1);
        }


        if(p[pp] == '*'){
            pick = memo(dp, s, p, sp + 1, pp);
            not_pick = memo(dp, s, p, sp, pp + 1);
        }

        dp[sp][pp] = not_pick || same || pick;

        return dp[sp][pp];
    }
};