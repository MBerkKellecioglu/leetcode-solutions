class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<vector<int>> checked(land.size(), vector<int>(land[0].size(), 0));
        vector<vector<int>> sol;

        int m = land.size(), n = land[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(land[i][j] == 1 && checked[i][j] == 0){
                    vector<int> candidates{INT_MAX, INT_MAX, INT_MIN, INT_MIN};
                    dfs(land, candidates, checked, sol, i, j, m, n);
                }
            }
        }

        return sol;
    }

    void dfs(vector<vector<int>>& land, vector<int>& candidates, vector<vector<int>>& checked, vector<vector<int>>& sol, int x, int y, int& m, int& n){

        checked[x][y] = 1;

        int flag = 0;

        if(candidates[0] >= x && candidates[1] >= y){
            candidates[0] = x;
            candidates[1] = y;
        }

        if(candidates[2] <= x && candidates[3] <= y){
            candidates[2] = x;
            candidates[3] = y;
        }

        if(x + 1 < m && checked[x + 1][y] == 0 && land[x + 1][y] == 1){
            flag = 1;
            dfs(land, candidates, checked, sol, x + 1, y, m, n);
        }
        if(x - 1 > -1 && checked[x - 1][y] == 0 && land[x - 1][y] == 1){
            flag = 1;
            dfs(land, candidates, checked, sol, x - 1, y, m, n);
        }
        if(y + 1 < n && checked[x][y + 1] == 0 && land[x][y + 1] == 1){
            flag = 1;
            dfs(land, candidates, checked, sol, x, y + 1, m, n);
        }
        if(y - 1 > -1 && checked[x][y - 1] == 0 && land[x][y - 1] == 1){
            flag = 1;
            dfs(land, candidates, checked, sol, x, y - 1, m, n);
        }

        if(flag == 0) sol.push_back(candidates);

        return;
    }
};