using ll = long long;

class Solution {
public:
    ll maximumHappinessSum(vector<int>& happy, int k) {
        

        sort(happy.begin(), happy.end());

        ll i = happy.size() - 1, dec = 0, ans = 0;

        while(k > 0){
            ans += (happy[i] - dec > -1) ? happy[i] - dec : 0;
            dec++;
            k--;
            i--;
        }

        return ans;
    }
};