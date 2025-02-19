class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        if(nums.size() == 1) return nums[0];
        
        int sz = 1, ans = 1, inc = -1;

        if(nums[0] > nums[1]) inc = 0;
        else if(nums[0] < nums[1]) inc = 1;
        else inc = -1;

        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                if(inc == 0) sz++;
                else sz = 2;

                inc = 0;
            }
            else if(nums[i] < nums[i + 1]){
                if(inc == 1) sz++;
                else sz = 2;

                inc = 1;
            }
            else{
                sz = 1;
                inc = -1;
            }

            ans = max(sz, ans);
        }

        return ans;
    }
};