class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.size() == 0) return "";

        string sol = "";

        int ind = 0;
        
        while(1){
            if(strs[0] == "") return "";
            
            char curr = strs[0][ind];

            for(int i = 0; i < strs.size(); i++){
                if(ind >= strs[i].size() || strs[i][ind] != curr) return sol;
            }

            sol += curr;
            ind++;
        }
    }
};