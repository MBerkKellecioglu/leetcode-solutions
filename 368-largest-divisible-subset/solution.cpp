class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums){

        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<int> ans = {};

        vector<vector<int>> dp(nums.size(), vector<int>());

        for(int i = n - 1; i > -1; i--){
            int curr_num = nums[i];
            vector<int> curr_sub = {curr_num};
            bool flag = 0;

            for(int j = i + 1; j < nums.size(); j++){
                if( ((curr_num % nums[j] == 0) || (nums[j] % curr_num == 0) ) && dp[j].size() >= curr_sub.size()){
                    curr_sub = dp[j];
                    flag = 1;
                }
            }

            if(flag) curr_sub.insert(curr_sub.begin(), curr_num);

            dp[i] = curr_sub;

            ans = (ans.size() < dp[i].size()) ? dp[i] : ans;
        }

        return ans;
    }
};