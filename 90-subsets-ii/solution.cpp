class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> sol;
        sol.push_back({});
        sort(nums.begin(), nums.end());

        recSet(nums, {}, sol, 0);

        return sol;
    }

    void recSet(vector<int>& nums, vector<int> sub_set, vector<vector<int>>& sol, int ind){

        if(sub_set.size() >= nums.size() || ind >= nums.size()) return;
        
        for(int i = ind; i < nums.size(); i++){
            sub_set.push_back(nums[i]);
            sol.push_back(sub_set);
            recSet(nums, sub_set, sol, i + 1);
            sub_set.pop_back();
            if(i + 1 < nums.size() && nums[i] == nums[i + 1]) while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
    }
};