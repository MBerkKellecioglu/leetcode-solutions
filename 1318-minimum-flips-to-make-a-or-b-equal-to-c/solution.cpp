class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int maxi = max({a,b, c});

        int sz = (int)log2(maxi)+1;

        int ans = 0;

        while(sz > 0){
            int lsb_a = a & 1;
            int lsb_b = b & 1;

            int lsb_c = c & 1;

            if( (lsb_a | lsb_b) != lsb_c){
                if(lsb_a & lsb_b) ans += 2;
                else ans++;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
            sz--;
        }

        return ans;
    }
};