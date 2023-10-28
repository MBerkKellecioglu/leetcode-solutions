class Solution {
public:
    
    int longestConsecutive(vector<int>& nums){
        int length = 0;
        int max_length = 0;
        std::set<int> sol(nums.begin(), nums.end());
        for(auto it : sol){
            if(sol.find(it - 1) != sol.end() ) continue;
            else{
                while(sol.find(it + length) != sol.end()) length++;
                if(length > max_length) max_length = length;
                length = 0;
            }
        }
        return max_length;
    }
};