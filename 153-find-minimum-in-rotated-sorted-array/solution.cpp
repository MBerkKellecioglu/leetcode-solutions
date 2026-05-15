class Solution {
public:
    int findMin(vector<int>& nums){
        int left_ind = 0, right_ind = nums.size() - 1, mid_ind, min_val = 5001;
 
        if(nums[0] < nums[nums.size() - 1] || nums.size() == 1) return nums[0];

        while(left_ind <= right_ind){
            if(nums[left_ind] < nums[0]) break;
            mid_ind = (left_ind + right_ind) / 2;
            if(nums[mid_ind] < nums[left_ind]) right_ind = mid_ind - 1;
            else left_ind = mid_ind + 1;
        }

        return nums[left_ind]; 
    }
};