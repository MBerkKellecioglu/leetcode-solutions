class Solution {
public:
    int maxOperations(string s) {
        
        int i = s.size() - 1;

        while(i > -1 && s[i] == '1'){
            i--;
        }

        int total_one_count = 0, ans = 0;


        for(i; i > -1; i--){
            if(s[i] == '1'){
                int curr_one_count = 0;
                total_one_count++;

                while(i > -1 && s[i] == '1'){
                    curr_one_count++;
                    i--;
                }

                ans += curr_one_count * total_one_count;
            }
        }

        return ans;
    }
};