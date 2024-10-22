class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n = grid.size(), ans = 0;

        map<vector<int>, int> cache;

        for(int i = 0; i < n; i++) cache[grid[i]]++;

         for(int i = 0; i < n; i++){
            vector<int> col;
            for(int j = 0; j < n; j++){
                col.push_back(grid[j][i]);
            }
            
            ans += cache[col];
        }

        return ans;
    }
};