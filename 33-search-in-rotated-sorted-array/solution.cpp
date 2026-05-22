class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(target == nums[mid]) return mid;

            /* if our left val is lesser than mid val than that means our left and mid pointer
               is at the same portion of the array */
            if(nums[left] <= nums[mid]){
                /* since we understood that our mid and left pointer is at the same portion(we dont know which) if 
                   our target is bigger than mid than its simple binary search logic(dont matter which portion) or if our target is 
                   lesser than left val that actually means we are at the left portion of the array so we need to go right*/
                if(target > nums[mid] || target < nums[left]) left = mid + 1;
                else right = mid - 1;
                /* if you wondered if there might be a case where our target is actually at the left side of the left pointer and our left pointer 
                    might be at right portion than our target would be lesser than left val but instead of going right we should go left. That is impossible*/
            }
            else{
                // same logic for right pointer
                if(target < nums[mid] || target > nums[right]) right = mid - 1;
                else left = mid + 1;
            }
        }

        return - 1;   
    }
};