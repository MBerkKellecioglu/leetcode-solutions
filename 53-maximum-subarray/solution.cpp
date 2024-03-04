class Solution {
public:
    int maxSubArray(vector<int>& nums){

       if(nums.size() == 1) return nums[0];

       vector<int> dp(nums.size() + 1, INT_MIN);

       dp[nums.size() - 1] = nums.back();

       int sol = INT_MIN;

       for(int i = nums.size() - 2; i > -1; i--){
           dp[i] = max({nums[i], nums[i] + dp[i + 1], nums[i] + nums[i + 1]});
           sol = max(dp[i], sol);
        }

        sol = max(sol, dp[nums.size() - 1]);

        return sol;
    }
};