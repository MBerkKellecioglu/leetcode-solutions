class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        
        unordered_map<int, int> multpl;

        int ans = 0, curr;

        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                curr = ++multpl[nums[i] * nums[j]];

                if(curr > 1) ans += (curr - 1) * 8;
            }
        }

        return ans;
    }
};