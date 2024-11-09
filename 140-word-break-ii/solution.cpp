class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> dp(s.size() + 1);

        vector<string> ans;

        for(int i = s.size() - 1; i > -1; i--){
            for(string& word : wordDict){ 
                if(i + word.size() <= s.size()){

                    string tmp = s.substr(i, word.size());

                    if(tmp == word){
                        if(!dp[i + word.size()].size()){
                            dp[i].push_back(word);
                        }
                        else{
                            for(auto st : dp[i + word.size()]) dp[i].push_back(word + " " + st);
                        }
                    }
                }
            }
        }

        for(auto st : dp[0]){
            int count = 0;
            
            for(auto c : st){
                if(c != ' ') count++;
            }
            if(count == s.size()) ans.push_back(st);
        }

        return ans;   
    }
};