class Solution {
public:
    int missingNumber(vector<int>& nums){

        int n = nums.size();

        int num1 = 0, num2 = 0;

        for(int i = 0; i < n; i++){
            num1 ^= i;
            num2 ^= nums[i];
        }

        num1 ^= n;

        return num1 ^ num2;
    }
};