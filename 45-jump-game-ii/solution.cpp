class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);

        for(int i = nums.size() - 2; i > -1; i--){
            if(nums[i] >= 1){
                int mini = INT_MAX;
                for(int inc = 1; inc < nums[i] + 1; inc++){
                    if(i + inc < nums.size() && dp[i + inc] != -2) mini = min(mini, dp[i + inc]);
                }
                if(mini == INT_MAX){
                    dp[i] = -2;
                    continue;
                }

                dp[i] = 1 + mini;
            }
            else dp[i] = -2; // -2 means we should skip //
        }

        return dp[0];
    }
};