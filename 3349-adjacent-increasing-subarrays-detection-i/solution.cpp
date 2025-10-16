class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        int curr = 1, prev = -1;

        for(int i = 1; i < nums.size(); i++){

            if(nums[i] > nums[i - 1]) curr++;
            else{
                if( (curr / 2 >= k) || min(curr, prev) >= k) return true;
                prev = curr;
                curr = 1;
            }
        }

        if((curr / 2 >= k) || min(curr, prev) >= k) return true;
        
        return false;
    }
};