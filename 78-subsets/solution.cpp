class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol = {{}};

        recSet(nums, {} ,sol, 0);

        return sol;
    }

    void recSet(vector<int> nums, vector<int> sub_set, vector<vector<int>>& sol, int ind){
        if(sub_set.size() >= nums.size() || ind >= nums.size()) return;

        sub_set.push_back(nums[ind]);

        sol.push_back(sub_set);

        recSet(nums, sub_set, sol, ind + 1);

        sub_set.pop_back();

        recSet(nums, sub_set, sol, ind + 1);
    }
};