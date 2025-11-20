using ll = long long;

class Solution {
public:
    int numSub(string s) {
        
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            ll one_count = 0;

            while(s[i] == '1'){
                one_count++;
                i++;
            }

            ll inc = (one_count * (one_count + 1)) / 2;

            inc %= 1000000000 + 7;

            ans += inc;

            ans %= 1000000000 + 7;
        }

        return ans;
    }
};