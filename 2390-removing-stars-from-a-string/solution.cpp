class Solution {
public:
    string removeStars(string s) {
        
        stack<char> cache;
        
        string ans = "";

        for(auto& c : s){
            if(c == '*') cache.pop();
            else cache.push(c);
        }

        while(!cache.empty()){
            ans += cache.top();
            cache.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};