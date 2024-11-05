class Solution {
public:
    int minChanges(string s) {
        
        int lb = 0, rb = 2, n = s.size(), ans = 0;

        while(rb <= n){

            if((s[lb] == '1' ^ s[lb + 1] == '1')) ans++;

            lb = rb;
            rb += 2; 
        }

        return ans;
    }
};