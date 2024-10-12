class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1]){
                int j = i;
                while(j + 1 < nums.size() && nums[j] == nums[j + 1]){
                    j++;
                }
                nums.erase(nums.begin() + i + 1, nums.begin() + j + 1);
            }
        }

        return nums.size();
    }
};