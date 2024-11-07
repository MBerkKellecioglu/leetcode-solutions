class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        
        vector<int> set_bits;

        for(int& n : nums){
            set_bits.push_back(countBits(n));
        }

        int prev_maxi = -1, n = set_bits.size();


        for(int i = 0; i < n; i++){
            int mini = nums[i];
            int maxi = nums[i];

            while(i + 1 < n && set_bits[i] == set_bits[i + 1]){
                i++;
                mini = min(mini, nums[i]);
                maxi = max(maxi, nums[i]);
            }

            if(mini < prev_maxi){
                return false;
            }

            prev_maxi = maxi;
        }

        return true;
    }

    int countBits(int num){

        int set_bit = 0;

        while(num > 0){
            if(num & 1) set_bit++;
            
            num = num>>1;
        }

        return set_bit;
    }
};