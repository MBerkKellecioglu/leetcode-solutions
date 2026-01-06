class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        
        set<string> ans;
        string construct = "";

        int left = 0, right = 0;

        for(char c : s){
            if(c == '(') left++;
            else if(c == ')'){
                if(left > 0) left--;
                else right++;
            }
        }  

        left += right;

        dfs(ans, s, construct, 0, 0, true, left);

        return vector<string>(ans.begin(), ans.end());
    }

    void dfs(set<string>& ans, string& main, string& construct, int ind, int left, bool valid, int& remove){
        
        if(ind >= main.size() && valid && main.size() == construct.size() + remove){
            ans.insert(construct);
            return;
        }
        
        if(main[ind] == '('){
            construct.push_back(main[ind]);
            dfs(ans, main, construct, ind + 1, left + 1, false, remove);
            construct.pop_back();

            valid = (left == 0) ? true : false;
            dfs(ans, main, construct, ind + 1, left, valid, remove);
        }
        else if(main[ind] == ')'){
            if(left - 1 > -1){
                construct.push_back(main[ind]);
                valid = (left - 1 == 0) ? true : false; 
                dfs(ans, main, construct, ind + 1, left - 1, valid, remove);
                construct.pop_back();
            }

            valid = (left == 0) ? true : false;
            dfs(ans, main, construct, ind + 1, left, valid, remove);
        }
        else if(isalpha(main[ind])){
            construct.push_back(main[ind]);
            dfs(ans, main, construct, ind + 1, left, valid, remove);
            construct.pop_back();
        }
    }
};