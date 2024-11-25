class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

        int n = nums.size(), curr = nums[0];
        
        vector<int> ans(n, 0);

        ans[n - 1] = flipBits(curr, maximumBit);

        for(int i = 1; i < nums.size(); i++){
            curr = curr ^ nums[i];
            ans[n - (i + 1)] = flipBits(curr, maximumBit);
        }

        return ans;
    }

    int flipBits(int num, int& maxBit){
        
        bitset<32> x = num;

        for(int i = 0; i < maxBit; i++){
            x[i] = x[i] ^ 1;
        }

        return x.to_ulong();
    }
};