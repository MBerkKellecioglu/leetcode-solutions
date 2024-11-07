class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        int check = 1, ans = 0;

        for(int i = 0; i < 24; i++){
            int freq = 0;
            for(int& c : candidates){
                if( (c & check) == check) freq++;
            }

            ans = max(ans, freq);
            check = check<<1;
        }

        return ans;
    }
};