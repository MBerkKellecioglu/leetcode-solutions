class Solution {
public:
    int findDuplicate(vector<int>& nums){
        int slow = 0, fast = 0, slow2 = 0;

        do{
            slow = nums[slow];
            fast = nums[nums[fast]]; // find end of the cycle //
        }while(slow != fast);

        do{
            slow = nums[slow];
            slow2 = nums[slow2]; // find start of the cycle //
        }while(slow != slow2);

        return slow; // start of the cycle is the repeated number //
    }
};