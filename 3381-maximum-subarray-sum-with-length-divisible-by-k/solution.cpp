using ll = long long;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        
        vector<ll> rsum(k, LLONG_MAX);

        ll ans = LLONG_MIN, sum = 0;

        rsum[0] = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            int remainder = (i + 1) % k;

            if(rsum[remainder] != LLONG_MAX){
                ans = max(ans, sum - rsum[remainder]);
            }

            rsum[remainder] = min(rsum[remainder], sum);
        }

        return ans;
    }
};