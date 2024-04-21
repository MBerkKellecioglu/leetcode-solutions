class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        map<char, char> s_converter;

        map<char, char> t_converter;

        for(int i = 0; i < s.size(); i++){

            if(s_converter.find(s[i]) == s_converter.end() && t_converter.find(t[i]) == t_converter.end()){
                s_converter[s[i]] = t[i];
                t_converter[t[i]] = s[i];
                s[i] = t[i];
            }
            else if(s_converter.find(s[i]) != s_converter.end()){
                s[i] = s_converter[s[i]];
            }
            else if(t_converter.find(t[i]) != t_converter.end()){
                t[i] = t_converter[t[i]];
            }
        }

        if(s == t) return true;

        return false;
    }
};