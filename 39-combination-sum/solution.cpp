class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> sol;
        vector<int> sub_sol;
        
        recSum(candidates, target, sol, sub_sol, 0);

        return sol;
    }

    void recSum(vector<int>& candidates, int target, vector<vector<int>>& sol, vector<int>& sub_sol,int ind){
        if(ind >= candidates.size() || target <= 0){

            if(target == 0) sol.push_back(sub_sol);
            
            return;
        }

        if(candidates[ind] <= target){
            sub_sol.push_back(candidates[ind]);
            recSum(candidates, target - candidates[ind], sol, sub_sol, ind);
            sub_sol.pop_back();
        }
        recSum(candidates, target, sol, sub_sol, ind + 1);
    }
};