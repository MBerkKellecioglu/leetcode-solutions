class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums){

        int r = 0, l = 0, ans = INT_MAX, sum = 0, n = nums.size();

        while(r < n){
            sum += nums[r];
            r++;

            while(l < r && sum >= target){
                ans = min(ans, r - l);
                sum -= nums[l];
                l++;
            }
        }

        return ans = (ans == INT_MAX) ? 0 : ans;
    }
        
};