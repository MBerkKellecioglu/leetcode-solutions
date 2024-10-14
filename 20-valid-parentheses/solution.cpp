class Solution {
public:
    bool isValid(string s) {
        
        stack<char> cache;
        map<char, char> close_brackets{{')', '('}, {']', '['}, {'}', '{'}};

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                cache.push(s[i]);
            }
            else{
                char tmp = close_brackets[s[i]];
                if(cache.empty() || cache.top() != tmp) return false;
                else cache.pop();
            }
        }

        if(!cache.empty()) return false;

        return true;
    }
};