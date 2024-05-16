class Solution {
public:
    int longestIdealString(string s, int k){
        
        vector<int> alpha(26, 0);

        int sol = 0;

        for(int i = s.size() - 1; i > -1; i--){
            sol = max(sol, checkIteration(alpha, s[i], k));
        }   

        return sol;
    }

    int checkIteration(vector<int>& alpha, char& c, int& k){
        
        int max_val = 0;

        for(int i = c - 97 - k; i <= c - 97 + k; i++){
            if(i < 0 || i > 25) continue;
            else{
                max_val = max(max_val, alpha[i]);
            }
        }

        return alpha[c - 97] = max_val + 1;

    }
};