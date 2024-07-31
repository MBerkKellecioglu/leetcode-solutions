class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size() - 1, ind = -1;

        while(l <= r){
            int mid = (l + r) / 2;

            if(nums[mid] < target) l++;
            else if(nums[mid] > target) r--;
            else{
                ind = mid;
                break;
            }
        }

        if(ind == -1) return {-1, -1};

        int sol1 = ind, sol2 = ind;

        if(sol1 - 1 > -1 && nums[sol1] == nums[sol1 - 1]){
            while(sol1 - 1 > -1 && nums[sol1] == nums[sol1 - 1]) sol1--;
        }

        if(sol2 + 1 < nums.size() && nums[sol2] == nums[sol2 + 1]){
            while(sol2 + 1 < nums.size() && nums[sol2] == nums[sol2 + 1]) sol2++;
        }

        return {sol1, sol2};
    }
};