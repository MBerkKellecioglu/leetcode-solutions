using ll = long long;

class Solution {
public:
    int numOfWays(int n) {
        
        ll pattern1 = 6;
        ll pattern2 = 6;

        int MOD = pow(10,9) + 7;

        for(int i = 2; i < n + 1; i++){
            ll new1 = (pattern1 * 3 + pattern2 * 2) % MOD;

            ll new2 = (pattern1 * 2  + pattern2 * 2) % MOD;

            pattern1 = new1;
            pattern2 = new2;
        }

        return (pattern1 + pattern2) % MOD;
    }
};