class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        unordered_map<int, int> cache;
        vector<vector<int>> freq(nums.size() + 1, vector<int>(0,0));
        vector<int> sol;
        
        for(int elements : nums) cache[elements]++;

        for(auto elements : cache) freq[elements.second].push_back(elements.first);

        for(int i = freq.size() - 1; i > -1; i--){
            vector<int> tmp = freq[i];
            if(!tmp.empty()) sol.insert(sol.end(), tmp.begin(), tmp.end());
            if(sol.size() >= k) return sol;
        }
        
        return sol;
    }  
};