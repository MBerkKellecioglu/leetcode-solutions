class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        string ans = "";

        int sz = part.size();


        for(char c : s){
            ans += c;

            if(ans.size() >= sz && ans.substr(ans.size() - sz) == part){

                for(int i = 0; i < sz; i++){
                    ans.pop_back();
                }
            }
        }
        
        return ans;
    }
};