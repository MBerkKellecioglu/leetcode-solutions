class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        
        vector<int> ans(n * 2 - 1, -1);

        vector<bool> cand(n + 1, false);

        bool finish = false;

        dfs(ans, cand, finish);

        return ans;
    }
    
    void dfs(vector<int>& ans, vector<bool>& cand, bool& finish){

        int ind = 0;

        while(ind < ans.size() && ans[ind] != -1) ind++;

        if(ind >= ans.size()){
            finish = true;
            return;
        }

        for(int i = cand.size() - 1; i > 0; i--){
            if(!cand[i] && (i == 1 || (ind + i < ans.size() && ans[ind + i] == -1)) ){
                ans[ind] = i;
                cand[i] = true;

                if(i != 1) ans[ind + i] = i;

                if(!finish) dfs(ans, cand, finish);

                if(!finish){
                    ans[ind] = -1;
                    cand[i] = false;

                    if(i != 1) ans[ind + i] = -1;
                }
            }
        }
    }
};