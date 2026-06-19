class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        vector<int> alt(gain.size() + 1, 0);

        int ans = 0;

        for(int i = 1; i < alt.size(); i++){
            alt[i] = alt[i - 1] + gain[i - 1];
            ans = max(alt[i], ans);
        }

        return ans;
    }
};