class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums){
        set<vector<int>> sol;
        vector<int> used_index(nums.size(), 0);

        recPermute(nums, sol, {}, used_index);

        vector<vector<int>> converted(sol.begin(), sol.end());

        return converted;
    }

    void recPermute(vector<int>& nums, set<vector<int>>& sol, vector<int> sub_sol, vector<int> used_index){
        if(nums.size() == sub_sol.size()){
            sol.insert(sub_sol);
            return;
        }
        else if(nums.size() < sub_sol.size()) return;

        for(int i = 0; i < nums.size(); i++){
            if(!used_index[i]) sub_sol.push_back(nums[i]);
            else continue;
            used_index[i]++;
            recPermute(nums, sol, sub_sol, used_index);
            sub_sol.pop_back();
            used_index[i]--;
        }
    }
};