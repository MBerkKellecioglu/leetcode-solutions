class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int count = 0, n = nums.size();

        for(int i = 0; i < n; i++){
            if(!nums[i]) count++;
            else{
                nums[i - count] = nums[i];
            }
        }

        for(int i = n - count; i < n; i++){
            nums[i] = 0;
        }

    }
};