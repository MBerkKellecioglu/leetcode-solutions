class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(target == nums[mid]) return true;
        
            if(nums[left] < nums[mid]){
                if(target > nums[mid] || target < nums[left]) left = mid + 1;
                else right = mid - 1;
            }
            else if(nums[left] > nums[mid]){
                if(target < nums[mid] || target > nums[right]) right = mid - 1;
                else left = mid + 1;
            }
            else left++;
        }

        return 0;   
    }
};