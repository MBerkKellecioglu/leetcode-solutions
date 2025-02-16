using ll = long long;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        unordered_map<ll, ll> cache;

        ll ans = ((nums.size() - 1) * nums.size()) / 2;

        for(int i = 0; i < nums.size(); i++){
            cache[i - nums[i]]++;
        }

        for(auto e : cache){
            if(e.second > 1) ans -= ((e.second - 1) * e.second) / 2;
        }

        return ans;
    }
};