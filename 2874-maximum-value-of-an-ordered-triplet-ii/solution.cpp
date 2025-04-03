using ll = long long;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        ll ans = 0, max_val = nums[0], max_diff = INT_MIN;


        for(int i = 1; i < nums.size(); i++){
            
            ans = max(ans, max_diff * ll(nums[i]));

            if(i <= nums.size() - 3){
                if(max_val < nums[i]){
                    max_val = nums[i];
                    continue;
                }
            }

            if(i <= nums.size() - 2){
                if(max_diff < max_val - nums[i]){
                    max_diff = max_val - nums[i];
                    continue;
                }
            }
        }

        return ans;
    }
};