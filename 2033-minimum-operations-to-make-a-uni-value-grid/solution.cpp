class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int remainder = grid[0][0] % x, m = grid.size(), n = grid[0].size(), ans = 0;

        vector<int> sorted;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int curr = grid[i][j];
                
                if(curr % x != remainder) return -1;
                else sorted.push_back(curr);
            }
        }

        sort(sorted.begin(), sorted.end());

        int median = sorted[(m * n) / 2];

        for(int num : sorted){
            ans += abs(num - median) / x;
        }

        return ans;
    }
};