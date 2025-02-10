class Solution {
public:
    string clearDigits(string s) {
        
        int p = 0;

        while(p > -1 && p < s.size()){
            if(isdigit(s[p])){
                s.erase(p - 1, 2);
                p--;
                continue;
            }
            p++;
        }

        return s;
    }
};