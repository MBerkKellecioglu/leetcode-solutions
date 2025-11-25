class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        int prev_mod = 1 % k, ans = 1, add_mod = 10 % k;

        bool flag = false;

        if(!prev_mod) return 1;

        for(int i = 1; i < k; i++){
            if( ( (i * add_mod) + 1) % k == 0) flag = true;
        }

        if(!flag) return -1;

        while(1){
            int curr_mod = ((prev_mod * add_mod) + 1) % k;

            ans++;

            if(!curr_mod) return ans;

            prev_mod = curr_mod;
        }

        return 0;
    }
};