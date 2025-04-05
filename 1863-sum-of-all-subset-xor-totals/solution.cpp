class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        int ans = 0;

        dfs(nums, ans, 0, 0);

        return ans;
    }

    void dfs(vector<int>& nums, int& ans, int ind, int curr){

        if(ind >= nums.size()){
            ans += curr;
            return;
        }

        dfs(nums, ans, ind + 1, curr ^ nums[ind]);
        dfs(nums, ans, ind + 1, curr);

        return;
    }
};