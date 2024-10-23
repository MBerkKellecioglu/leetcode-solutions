class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> freq1;
        map<int,int> freq2;
        vector<int> dist;
        vector<vector<int>> ans;

        for(int& num : nums1) freq1[num]++;

        for(int& num : nums2) freq2[num]++;

        for(auto& e : freq1) if(freq2[e.first] < 1) dist.push_back(e.first);

        ans.push_back(dist);
        dist.clear();

        for(auto& e : freq2) if(freq1[e.first] < 1) dist.push_back(e.first);
        
        ans.push_back(dist);
        
        return ans;
    }
};