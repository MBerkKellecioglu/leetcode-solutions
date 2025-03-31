class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int l = 0, r = 1, sum = nums[0], ans = 1;

        while(r < nums.size()){
            if( (sum & nums[r]) == 0){
                sum = (sum | nums[r]);
                ans = max(ans, r - l + 1);
                r++;
            }
            else{
                while(l < r && ( (nums[r] & sum) != 0) ){
                    sum -= nums[l];
                    l++;
                }
            }
        }

        return ans;
    }
};