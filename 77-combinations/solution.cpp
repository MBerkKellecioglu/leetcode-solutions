class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        vector<vector<int>> sol;
        vector<int> sub_sol;

        for(int i = 1;  i < n + 1; i++) nums.push_back(i);

        rec(sol, nums, sub_sol, 0, k);

        return sol;
    }

    void rec(vector<vector<int>>& sol, vector<int>& nums, vector<int>& sub_sol, int ind, int& k){

        if(sub_sol.size() == k){
            sol.push_back(sub_sol);
            return;
        }

        if(ind >= nums.size()) return;

        sub_sol.push_back(nums[ind]);
        rec(sol, nums, sub_sol, ind + 1, k);
        
        sub_sol.pop_back();

        rec(sol, nums, sub_sol, ind + 1, k);
    }
};