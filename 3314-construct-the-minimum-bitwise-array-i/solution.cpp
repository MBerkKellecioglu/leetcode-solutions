class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        vector<int> ans;

        for(int num : nums){
            int nth = 0, mask = 1;

            while ((num >> nth) & 1){
                nth++;
                mask <<= 1;
            }

            mask >>= 1;

            (mask != 0) ? ans.push_back(num ^ mask) : ans.push_back(-1);
        }

        return ans;
    }
};