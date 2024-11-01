class Solution {
public:
    string makeFancyString(string s) {
        
        string ans = "";

        s += "/";

        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == s[i + 1]){

                while(s[i] == s[i + 1]) i++;
                
                ans += string(2, s[i]);
            }
            else ans += string(1, s[i]);
        }

        return ans;
    }
};