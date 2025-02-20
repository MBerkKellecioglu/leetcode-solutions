class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        string binary = "";
        string ans = "";

        unordered_map<string, int> cache;

        int n = nums[0].size();

        bool flag = false;

        for(string& s : nums) cache[s]++;

        dfs(binary, ans, cache, n, flag);

        return ans;
    }

    void dfs(string& binary,  string& ans, unordered_map<string, int>& cache, int& n, bool& flag){

        if(flag) return;
        
        if(binary.size() == n){
            if(cache.find(binary) == cache.end()){
                ans = binary;
                flag = true;
            }
            return;
        }

        binary += "1";

        dfs(binary, ans, cache, n, flag);

        binary.pop_back();

        binary += "0";

        dfs(binary, ans, cache, n, flag);

        binary.pop_back();
        
    }
};