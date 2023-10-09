class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        unordered_map<string, vector<string>> cache;
        string tmp;
        vector<vector<string>> sol;

        for(string elements : strs){
            tmp = elements;
            sort(tmp.begin(), tmp.end());
            cache[tmp].push_back(elements);
        }

        for(auto elements : cache) sol.push_back(elements.second);

        return sol;
    }
};