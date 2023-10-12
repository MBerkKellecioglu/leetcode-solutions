class Solution {
public:
    string minWindow(string s, string t){
        unordered_map<char, int> cache;
        unordered_map<char, int> cache2;
        vector<int> sol_ind{-1,-1};
        int left_ind = 0, min_size = INT_MAX, count = 0;
        string sol = "";

        for(char c : t) cache[c]++;
        
        for(int right_ind = 0; right_ind < s.size(); right_ind++){
            char c = s[right_ind];
            cache2[c]++;
            if(t.find(c) != string::npos && cache[c] == cache2[c]) count++;
            while(count == cache.size()){
                if(right_ind - left_ind + 1 < min_size){
                    sol_ind[0] = left_ind;
                    sol_ind[1] = right_ind;
                    min_size = right_ind - left_ind + 1;
                }
                c = s[left_ind];
                cache2[c]--;
                if(t.find(c) != string::npos && cache2[c] < cache[c]) count--;
                left_ind++;
            }
        }
        if(min_size != INT_MAX) sol = s.substr(sol_ind[0], (sol_ind[1] - sol_ind[0] + 1));
        return sol;
    }
};