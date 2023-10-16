class Solution {
public:
    bool isAnagram(string s, string t){
        unordered_map<char,int> cache;

        if(s.size() != t.size()) return false;

        for(int i = 0; i < s.size(); i++){
            cache[s[i]]++;
            cache[t[i]]--;
        }
        for(auto elements : cache) if(elements.second != 0) return false;
        
        return true;
    }
};