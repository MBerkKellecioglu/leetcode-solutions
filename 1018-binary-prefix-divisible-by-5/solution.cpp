class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        
        vector<bool> ans;

        int prev_mod = nums[0];

        ans.push_back(!(prev_mod));

        for(int i = 1; i < nums.size(); i++){
            prev_mod = ((prev_mod * 2) + nums[i]) % 5;

            ans.push_back(!(prev_mod));
        }

        return ans;
    }
};