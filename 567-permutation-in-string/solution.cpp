class Solution {
public:
    bool checkInclusion(string s1, string s2){
        vector<int> cache(26,0);
        int right_ind = 0, left_ind = 0, flag = 0;
        vector<int> cache2(26,0);

        for(char c : s1) cache[c - 'a']++;

        while(right_ind < s2.size()){
            cache2[s2[right_ind] - 'a']++;
            if(right_ind - left_ind + 1 == s1.size()){
                if(cache2 == cache) return true;
                else{
                    cache2[s2[left_ind] - 'a']--;
                    left_ind++;
                }
            }
            right_ind++;
        }
        return false;
    }
};