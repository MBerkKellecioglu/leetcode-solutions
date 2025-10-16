class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {

        int sz = energy.size(), ans = INT_MIN;
        
        vector<int> sums(energy.size(), 0);

        for(int i = sz - 1; i > -1; i--){
            sums[i] = (i + k < sz) ? energy[i] + sums[i + k] : energy[i];

            ans = max(ans, sums[i]);
        }

        return ans;
    }
};