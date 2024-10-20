class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        
        for(int i = 0; i < s.size(); i++){
            expand(i, i, s, res);
            expand(i, i + 1, s, res);
        }

        return res;
    }

    void expand(int l, int r, string& s, int& res){

        while(l >= 0 && r < s.size() && s[l] == s[r]){
            res++;
            l--;
            r++;
        }
    }
};