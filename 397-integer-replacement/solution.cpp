using ll = long long;

class Solution {
public:
    int integerReplacement(int p) {
        
        int ans = 0;

        ll n = p;

        while(n != 1){
            if(n % 2 == 0) n /= 2;
            else{
                if( ((n - 1) / 2) % 2 == 0 || n == 3) n--;
                else n++;
            }

            ans++;
        }

        return ans;
    }
};