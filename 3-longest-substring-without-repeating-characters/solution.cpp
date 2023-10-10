class Solution {
public:
    int lengthOfLongestSubstring(string s){
        string sub_s;
        int sol = 0;

        for(char c : s){
            string tmp_s = string(1, c);
            if(sub_s.find(tmp_s) != string::npos){
                auto ind = sub_s.find(tmp_s);
                sol = max(sol, int(sub_s.size()));
                sub_s.erase(0, ind + 1);
                sub_s += tmp_s;
                continue;
            }
            sub_s += tmp_s;
        }
        sol = max(sol, int(sub_s.size()));
        return sol;
    }
};