class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map<int, int> freq;
        map<int, bool> freq2;

        for(auto& n : arr){
            freq[n]++;
        }

        for(auto e : freq){
            if(freq2.find(e.second) != freq2.end()) return false;

            freq2[e.second] = true;
        }

        return true;
    }
};