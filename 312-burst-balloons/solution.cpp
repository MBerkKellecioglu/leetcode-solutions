class Solution {
public:
    int maxCoins(vector<int>& nums){

        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2, -1));

        return dfs(nums, dp, 1, nums.size() - 2);
    }

    int dfs(vector<int>& nums, vector<vector<int>>& dp, int left, int right){

        if(left > right) return 0;
        
        if(dp[left][right] != -1) return dp[left][right];

        dp[left][right] = 0;
        int curr;

        for(int i = left; i < right + 1; i++){
            curr = nums[left - 1] * nums[i] * nums[right + 1];
            curr += dfs(nums, dp, left, i - 1) + dfs(nums, dp, i + 1, right);
            dp[left][right] = max(dp[left][right], curr);
        }

        return dp[left][right];
    }
};