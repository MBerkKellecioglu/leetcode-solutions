class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long long num1 = 0, num2 = 0;

        long long x = 0;

        for(int& n : nums) x ^= n;

        long long mask = x & (-x);

        for(long long num : nums){
            if(num & mask){
                num1 ^= num;
            }
            else num2 ^= num;
        }

        return {int(num1), int(num2)};

    }
};