class Solution {
public:
    int singleNumber(vector<int>& nums){
        
        int ans = 0;

        for(int i = 0; i < 32; i++){
            int ones = 0;
            for(int num : nums){
                ones += (num >> i) & 1;
            }

            if(ones % 3 != 0){
                int mask = 1 << i;

                ans = ans | mask;
            }
        }

        return ans;  
    }
};