class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = 0;

        for(int& n : nums) sum += n;

        int l = 0;

        for(int i = 0; i < nums.size(); i++){
            if(l == sum - l - nums[i]) return i;

            l += nums[i];
        }

        return -1; 
    }
};