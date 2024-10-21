class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size(), l = 0, r = 0, flag = 0, ind = 0, ans = 0, zero = 1;

        while(r < n){
            if(!nums[r]){
                if(!flag){
                    ind = r;
                    flag = 1;
                    zero = 0;
                }
                else{
                    ans = max(ans, r - l - flag);
                    l = ind + 1;
                    ind = r;
                }
            }

            r++;
        }

        ans = max(ans, r - l - flag);
        return ans - zero;
    }
};