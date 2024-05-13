class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> sol(n - 2, vector<int>(n - 2, 0));
        
        for(int i = 0; i + 3 <= n; i++){
            for(int j = 0; j + 3 <= n; j++){
                int max_val = 0;
                for(int k = i; k < i + 3; k++){
                    for(int t = j; t < j + 3; t++){
                        if(max_val < grid[k][t]) max_val = grid[k][t];
                    }
                }
                sol[i][j] = max_val;
            }
        }
        
        return sol;
    }
};