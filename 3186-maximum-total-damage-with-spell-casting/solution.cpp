using ll = long long;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        
        map<ll ,ll> freq;

        for(auto p : power) freq[p]++;

        set<ll> convert(power.begin(), power.end());
        vector<ll> powers(convert.begin(), convert.end());

        vector<ll> dp(powers.size(), 0);

        ll j = 0, ans = -1, mx = 0;
    
        for(int i = 0; i < powers.size(); i++){
            while(powers[j] < powers[i] - 2){
                mx = max(dp[j], mx);
                j++;
            }

            dp[i] = powers[i] * freq[powers[i]] + mx;

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};