class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        
        int curr = 1, prev = -1, ans = 1;

        for(int i = 1; i < nums.size(); i++){

            if(nums[i] > nums[i - 1]) curr++;
            else{
                ans = max(ans, (prev == curr) ? curr : max(min(curr, prev), curr / 2));
                prev = curr;
                curr = 1;
            }
        }

        ans = max(ans, (prev == curr) ? curr : max(min(curr, prev), curr / 2));

        return ans;
    }
};