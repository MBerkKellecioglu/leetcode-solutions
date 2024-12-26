class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target){

        map<pair<int, int>, int> dp;

        return dfs(nums, dp, target, 0, 0);
    }

    int dfs(vector<int>& nums, map<pair<int, int>, int>& dp, int& target, int count, int ind){

        if(ind == nums.size()){
            if(target == count){
                dp[{target, ind}] = 1;
                return 1;
            }
            else return 0;
        }

        if(dp.find({count, ind}) != dp.end()) return dp[{count, ind}];

        dp[{count, ind}] = dfs(nums, dp, target, count + nums[ind], ind + 1);
        dp[{count, ind}] += dfs(nums, dp, target, count - nums[ind], ind + 1);

        return dp[{count, ind}];
    }
};