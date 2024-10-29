class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        
        vector<int> sub;

        dfs(ans, sub, k, n, 0);

        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& sub, int& sz, int target, int ind){

        if(sub.size() == sz){
            if(!target) ans.push_back(sub);
            return;
        }

        for(int i = ind + 1; i < 10; i++){
            sub.push_back(i);
            target -= i;

            dfs(ans, sub, sz, target, i);

            sub.pop_back();
            target += i;
        }

    }
};