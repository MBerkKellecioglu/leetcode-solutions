class Solution {
public:
    int characterReplacement(string s, int k) {
        int left_ind = 0, max_freq = 0, sol = 0;
        map<char,int> cache;

        for(int right_ind = 0; right_ind < s.size(); right_ind++){
            int tmp = ++cache[s[right_ind]];
            max_freq = max(max_freq, tmp);
            if((right_ind - left_ind + 1 - max_freq) > k){
                cache[s[left_ind]]--;
                left_ind++;
            }
            sol = max(sol, (right_ind - left_ind + 1));
        }
        return sol;
    }
};