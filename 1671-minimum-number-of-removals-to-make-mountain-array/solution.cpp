class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int ans = INT_MAX, n = nums.size();
        
        vector<int> LIS = lengthOfLIS(nums);

        reverse(nums.begin(), nums.end());

        vector<int> LDS = lengthOfLIS(nums);

        reverse(LDS.begin(), LDS.end());

        for(int i = 1; i < n - 1; i++){
            if(min(LIS[i], LDS[i]) > 1){
                ans = min(ans, n - (LIS[i] + LDS[i] - 1));
            }
        }

        return ans;
    }

    vector<int> lengthOfLIS(vector<int>& nums){

        vector<int> dp;
        vector<int> all_dp(nums.size(), 0);

        int n = nums.size();

        for(int i = 0; i < n; i++){
            int lb = lowerBound(dp, nums[i]);

            if(lb >= dp.size()){
                dp.push_back(nums[i]);
            }
            else{
                dp[lb] = nums[i];
            }
            all_dp[i] = dp.size();
        }

        return all_dp;
    }

    int lowerBound(vector<int>& dp, int target){

        int l = 0, r = dp.size(), n = dp.size();

        while(l < r){
            int mid = (l + r) / 2;

            if(target <= dp[mid]){
                r = mid;
            }
            else if(target > dp[mid]){
                l = mid + 1;
            }
        }

        return l;
    }
};